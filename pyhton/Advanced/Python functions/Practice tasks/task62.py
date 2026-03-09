def sum_of_digits(n):
    s = 0
    for digit in str(abs(n)):
        s += int(digit)
    return s

a = int(input("1st numnb: "))
b = int(input("2nd number: "))

sum_a = sum_of_digits(a)
sum_b = sum_of_digits(b)

if sum_a > sum_b:
    print(f"sum of the number {a} more")
elif sum_b > sum_a:
    print(f"sum off the number {b} mor")
else:
    print("sum of the numbers are equal")