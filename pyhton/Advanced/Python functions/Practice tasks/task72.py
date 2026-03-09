import random

def detect_lucky(n):
    s = str(n)

    first_sum = int(s[0]) + int(s[1]) + int(s[2])
    last_sum = int(s[3]) + int(s[4]) + int(s[5])

    return first_sum == last_sum

def get_lucky():
    n = random.randint(100000, 999999)
    print(n)

    if detect_lucky(n):
        return n
    else:
        return get_lucky()

print(get_lucky())
