def find_speed(kilometers, hours):
    meter = kilometers * 1000
    seconds = hours * 3600
    return round(meter / seconds, 2)

print(find_speed(100, 3))