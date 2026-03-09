def detect_lucky(n):
    s = str(n)

    first_sum = int(s[0]) + int(s[1]) + int(s[2])
    last_sum = int(s[3]) + int(s[4]) + int(s[5])

    return first_sum == last_sum

print(detect_lucky(613073)) #true
print(detect_lucky(123456))#false