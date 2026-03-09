def sum_of_digits(n):
    s = 0
    for digit in str(abs(n)):
        s += int(digit)
    return s

print(sum_of_digits(1234))