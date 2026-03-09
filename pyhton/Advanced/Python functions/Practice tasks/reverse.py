import random

def get_random_array(n=10):
    result = []
    for i in range(n):
        result.append(random.randint(1, 100))
    return result

def reverse(lst):
    new_list = []
    for i in range(len(lst) - 1, -1, -1):
        new_list.append(lst[i])
    return new_list

arr = get_random_array()
reversed_arr = reverse(arr)
print(arr)
print(reversed_arr)