import random

def get_random_array(n=10):
    result = []
    for i in range(n):
        result.append(random.randint(1, 100))
    print(result)

get_random_array()