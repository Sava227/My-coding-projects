def sum_of_digits(n):
    return sum(int(digit) for digit in str(abs(n)))

num1 = int(input("2nd number "))
num2 = int(input("2st number: "))

if sum_of_digits(num1) > sum_of_digits(num2):
    print(f"Sum {num1} more")
elif sum_of_digits(num2) > sum_of_digits(num1):
    print(f"sum {num2} more")
else:
    print("sum of both numbers: ", sum_of_digits(n))