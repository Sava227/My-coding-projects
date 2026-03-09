// app.js
// Wires up the buttons in your index.html to the Flask backend endpoints.
//
// Endpoints expected:
//   POST /api/basic  { op, a, b }          -> { ok:true, result }
//   POST /api/eval   { expr }              -> { ok:true, result }
//   POST /api/power  { a, b }              -> { ok:true, result }
//   POST /api/root   { value, n }          -> { ok:true, result }
//   POST /api/solve  { equation }          -> { ok:true/false, solution, explanation }

async function postJSON(url, payload) {
  const res = await fetch(url, {
    method: "POST",
    headers: { "Content-Type": "application/json" },
    body: JSON.stringify(payload),
  });

  let data;
  try {
    data = await res.json();
  } catch {
    data = {};
  }

  if (!res.ok || data.ok === false) {
    throw new Error(data.error || "Request failed");
  }
  return data;
}

function setText(id, text) {
  const el = document.getElementById(id);
  if (el) el.textContent = text;
}

function getValue(id) {
  const el = document.getElementById(id);
  return el ? el.value : "";
}

function setValue(id, value) {
  const el = document.getElementById(id);
  if (el) el.value = value;
}

// --------------------
// Tabs
// --------------------
function initTabs() {
  const tabs = Array.from(document.querySelectorAll(".tab"));
  const panes = Array.from(document.querySelectorAll(".tabpane"));

  function activate(tabName) {
    tabs.forEach((t) => t.classList.toggle("active", t.dataset.tab === tabName));
    panes.forEach((p) => p.classList.toggle("active", p.id === tabName));
  }

  tabs.forEach((t) => {
    t.addEventListener("click", () => activate(t.dataset.tab));
  });
}

// --------------------
// Basic operations
// --------------------
function initBasic() {
  const outId = "basic-out";

  document.querySelectorAll("button[data-basic]").forEach((btn) => {
    btn.addEventListener("click", async () => {
      setText(outId, "Result: ...");
      try {
        const op = btn.dataset.basic;
        const a = getValue("basic-a");
        const b = getValue("basic-b");
        const data = await postJSON("/api/basic", { op, a, b });
        setText(outId, `Result: ${data.result}`);
      } catch (e) {
        setText(outId, `Error: ${e.message}`);
      }
    });
  });

  const clearBtn = document.getElementById("basic-clear");
  if (clearBtn) {
    clearBtn.addEventListener("click", () => {
      setValue("basic-a", "");
      setValue("basic-b", "");
      setText(outId, "Result: ");
    });
  }
}

// --------------------
// Expression evaluation
// --------------------
function initExpression() {
  const outId = "expr-out";

  const evalBtn = document.getElementById("expr-eval");
  if (evalBtn) {
    evalBtn.addEventListener("click", async () => {
      setText(outId, "Result: ...");
      try {
        const expr = getValue("expr-in");
        const data = await postJSON("/api/eval", { expr });
        setText(outId, `Result: ${data.result}`);
      } catch (e) {
        setText(outId, `Error: ${e.message}`);
      }
    });
  }

  const clearBtn = document.getElementById("expr-clear");
  if (clearBtn) {
    clearBtn.addEventListener("click", () => {
      setValue("expr-in", "");
      setText(outId, "Result: ");
    });
  }

  const exprInput = document.getElementById("expr-in");
  if (exprInput) {
    exprInput.addEventListener("keydown", (e) => {
      if (e.key === "Enter") {
        e.preventDefault();
        evalBtn?.click();
      }
    });
  }
}

// --------------------
// Power / Root
// --------------------
function initPowerRoot() {
  const outId = "powroot-out";

  const powGo = document.getElementById("pow-go");
  if (powGo) {
    powGo.addEventListener("click", async () => {
      setText(outId, "Result: ...");
      try {
        const a = getValue("pow-a");
        const b = getValue("pow-b");
        const data = await postJSON("/api/power", { a, b });
        setText(outId, `Result: ${data.result}`);
      } catch (e) {
        setText(outId, `Error: ${e.message}`);
      }
    });
  }

  const rootGo = document.getElementById("root-go");
  if (rootGo) {
    rootGo.addEventListener("click", async () => {
      setText(outId, "Result: ...");
      try {
        const value = getValue("root-value");
        const n = getValue("root-n");
        const data = await postJSON("/api/root", { value, n });
        setText(outId, `Result: ${data.result}`);
      } catch (e) {
        setText(outId, `Error: ${e.message}`);
      }
    });
  }

  const powClear = document.getElementById("pow-clear");
  if (powClear) {
    powClear.addEventListener("click", () => {
      setValue("pow-a", "");
      setValue("pow-b", "");
      setText(outId, "Result: ");
    });
  }

  const rootClear = document.getElementById("root-clear");
  if (rootClear) {
    rootClear.addEventListener("click", () => {
      setValue("root-value", "");
      setValue("root-n", "");
      setText(outId, "Result: ");
    });
  }
}

// --------------------
// Solve equation
// --------------------
function initSolve() {
  const outEl = document.getElementById("eq-out");
  const explainEl = document.getElementById("eq-explain");

  let lastX = "";

  const solveBtn = document.getElementById("eq-go");
  if (solveBtn) {
    solveBtn.addEventListener("click", async () => {
      if (outEl) outEl.textContent = "x = ...";
      if (explainEl) explainEl.textContent = "";

      try {
        const equation = getValue("eq-in");
        const data = await postJSON("/api/solve", { equation });

        lastX = String(data.solution ?? "");
        if (outEl) outEl.textContent = `x = ${data.solution}`;
        if (explainEl) explainEl.textContent = data.explanation || "";
      } catch (e) {
        lastX = "";
        if (outEl) outEl.textContent = `Error: ${e.message}`;
        if (explainEl) explainEl.textContent = "";
      }
    });
  }

  const clearBtn = document.getElementById("eq-clear");
  if (clearBtn) {
    clearBtn.addEventListener("click", () => {
      setValue("eq-in", "");
      lastX = "";
      if (outEl) outEl.textContent = "x = ";
      if (explainEl) explainEl.textContent = "";
    });
  }

  const copyBtn = document.getElementById("eq-copy");
  if (copyBtn) {
    copyBtn.addEventListener("click", async () => {
      if (!lastX) return;
      try {
        await navigator.clipboard.writeText(lastX);
        // Optional subtle feedback:
        // if (outEl) outEl.textContent = `x = ${lastX} (copied)`;
      } catch {
        // Clipboard can be blocked by browser settings; fail silently.
      }
    });
  }

  const eqInput = document.getElementById("eq-in");
  if (eqInput) {
    eqInput.addEventListener("keydown", (e) => {
      if (e.key === "Enter") {
        e.preventDefault();
        solveBtn?.click();
      }
    });
  }
}

// --------------------
// Boot
// --------------------
document.addEventListener("DOMContentLoaded", () => {
  initTabs();
  initBasic();
  initExpression();
  initPowerRoot();
  initSolve();
});