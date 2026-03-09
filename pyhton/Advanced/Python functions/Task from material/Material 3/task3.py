def count_passed(limit, *marks):
    if len(marks) == 1 and isinstance(marks[0], list):
        marks = marks[0]
    count = 0
    for mark in marks:
        if mark >= limit:
            count += 1
    return count

print(count_passed(3, 2, 4, 1, 3, 5))