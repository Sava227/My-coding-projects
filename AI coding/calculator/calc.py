import re
import ast
import operator as op
import math

from flask import Flask, request, jsonify, render_template

# -----------------------------
# Safe arithmetic evaluation
# -----------------------------
_ALLOWED_OPS = {
    ast.Add: op.add,
    ast.Sub: op.sub,
    ast.Mult: op.mul,
    ast.Div: op.truediv,
    ast.Pow: op.pow,
    ast.USub: op.neg,
    ast.UAdd: op.pos,
}

def safe_eval(expr: str) -> float:
    """
    Safely evaluate a numeric arithmetic expression with:
    +, -, *, /, **, parentheses, unary +/-.
    Examples: "2*3", "-4.5", "(2+1)*7", "2**3"
    """
    expr = expr.strip()
    if expr == "":
        raise ValueError("Empty expression")

    node = ast.parse(expr, mode="eval")

    def _eval(n):
        if isinstance(n, ast.Expression):
            return _eval(n.body)

        if isinstance(n, ast.Constant) and isinstance(n.value, (int, float)):
            return float(n.value)

        if isinstance(n, ast.UnaryOp) and type(n.op) in _ALLOWED_OPS:
            return _ALLOWED_OPS[type(n.op)](_eval(n.operand))

        if isinstance(n, ast.BinOp) and type(n.op) in _ALLOWED_OPS:
            return _ALLOWED_OPS[type(n.op)](_eval(n.left), _eval(n.right))

        raise ValueError(f"Unsupported expression: {expr!r}")

    return _eval(node)

# -----------------------------
# Calculator operations
# -----------------------------
def add(a: float, b: float) -> float:
    return a + b

def subtract(a: float, b: float) -> float:
    return a - b

def multiply(a: float, b: float) -> float:
    return a * b

def divide(a: float, b: float) -> float:
    if b == 0:
        raise ZeroDivisionError("Division by zero")
    return a / b

def power(a: float, b: float) -> float:
    return a ** b

def nth_root(a: float, n: float) -> float:
    if n == 0:
        raise ValueError("Root degree n cannot be 0")
    if a < 0 and float(n).is_integer() and int(n) % 2 == 0:
        raise ValueError("Even root of a negative number has no real result")
    if a < 0 and float(n).is_integer() and int(n) % 2 == 1:
        return -((-a) ** (1.0 / n))
    return a ** (1.0 / n)

# -----------------------------
# Equation solver: linear in x
# -----------------------------
def solve_equation(equation: str):
    eq = equation.replace(" ", "")

    if "=" not in eq:
        return "Error", "Equation must contain '='"

    left, right = eq.split("=", 1)

    def split_linear_terms(side: str):
        if side == "":
            return []

        terms = []
        start = 0
        depth = 0

        for i, ch in enumerate(side):
            if ch == "(":
                depth += 1
            elif ch == ")":
                depth -= 1
            elif depth == 0 and i > 0 and ch in "+-":
                terms.append(side[start:i])
                start = i

        terms.append(side[start:])
        return [t for t in terms if t]

    def parse_side(side: str):
        x_coeff = 0.0
        const = 0.0

        for raw_term in split_linear_terms(side):
            term = raw_term
            if term.startswith("+"):
                term = term[1:]

            if term == "" or term == "+":
                continue

            if "x" in term:
                if term.count("x") != 1:
                    raise ValueError("Only linear equations are supported (single 'x' per term).")
                if not term.endswith("x"):
                    raise ValueError("Unsupported form. Put x at the end of the term, e.g. '2x' not 'x2'.")
                coef_expr = term[:-1]
                if coef_expr == "":
                    coef_expr = "1"
                elif coef_expr == "-":
                    coef_expr = "-1"
                coef = safe_eval(coef_expr)
                x_coeff += coef
            else:
                const += safe_eval(term)

        return x_coeff, const

    try:
        left_x, left_const = parse_side(left)
        right_x, right_const = parse_side(right)
    except Exception as e:
        return "Error", f"Could not parse equation: {e}"

    total_x = left_x - right_x
    total_const = right_const - left_const

    if abs(total_x) < 1e-12:
        if abs(total_const) < 1e-12:
            return "Infinite solutions", "Equation simplifies to 0=0."
        return "No solution", f"Equation simplifies to 0={total_const}."

    x = total_const / total_x
    return x, f"Solved linear equation: x = {x}"

# -----------------------------
# Web App (Flask)
# -----------------------------
def _num_from(s: str) -> float:
    s = (s or "").strip().replace("^", "**")
    return safe_eval(s)

def create_app() -> Flask:
    app = Flask(__name__)

    @app.get("/")
    def home():
        return render_template("index.html")

    @app.post("/api/eval")
    def api_eval():
        data = request.get_json(force=True)
        expr = (data.get("expr") or "").strip()
        try:
            result = _num_from(expr)
            return jsonify(ok=True, result=result)
        except Exception as e:
            return jsonify(ok=False, error=str(e)), 400

    @app.post("/api/basic")
    def api_basic():
        data = request.get_json(force=True)
        op_name = (data.get("op") or "").strip()
        try:
            a = _num_from(data.get("a"))
            b = _num_from(data.get("b"))

            if op_name == "add":
                r = add(a, b)
            elif op_name == "sub":
                r = subtract(a, b)
            elif op_name == "mul":
                r = multiply(a, b)
            elif op_name == "div":
                r = divide(a, b)
            else:
                raise ValueError("Unknown operation")

            return jsonify(ok=True, result=r)
        except Exception as e:
            return jsonify(ok=False, error=str(e)), 400

    @app.post("/api/power")
    def api_power():
        data = request.get_json(force=True)
        try:
            a = _num_from(data.get("a"))
            b = _num_from(data.get("b"))
            return jsonify(ok=True, result=power(a, b))
        except Exception as e:
            return jsonify(ok=False, error=str(e)), 400

    @app.post("/api/root")
    def api_root():
        data = request.get_json(force=True)
        try:
            value = _num_from(data.get("value"))
            n = _num_from(data.get("n"))
            return jsonify(ok=True, result=nth_root(value, n))
        except Exception as e:
            return jsonify(ok=False, error=str(e)), 400

    @app.post("/api/solve")
    def api_solve():
        data = request.get_json(force=True)
        eq = (data.get("equation") or "").strip()
        solution, explanation = solve_equation(eq)
        ok = solution not in {"Error", "No solution"}
        return jsonify(ok=ok, solution=solution, explanation=explanation)

    return app

if __name__ == "__main__":
    app = create_app()
    app.run(host="127.0.0.1", port=5000, debug=True)
