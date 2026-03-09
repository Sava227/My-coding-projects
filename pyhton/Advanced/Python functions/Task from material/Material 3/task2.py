def rotate_first_and_second(sequence):
    if len(sequence) < 2:
        return sequence
    return sequence[2:] + sequence[:2]

print(rotate_first_and_second([1, 2, 3, 4, 5]))