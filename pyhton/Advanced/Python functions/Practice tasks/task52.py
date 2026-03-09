def factorial(n):
    result = 1
    for i in range(1, n + 1):
        result *= i
    return result

a = 2 * factorial(5)
b = 3 * factorial(8)
numerator = a + b

c = factorial(6)
d = factorial(4)
denominator = c + d

result = numerator / denominator
print(result)
