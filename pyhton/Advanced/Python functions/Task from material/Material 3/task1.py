fruits = ['mango', 'guava', 'kiwi', 'pomelo', 'pineapple', 'watermelon']
first, second, fifth, sixth, *remaining = fruits
print("1st position:", first)
print("2nd position:", second)
print("Middle ones: ", remaining)
print("5th position:", fifth)
print("The last one: ", sixth)