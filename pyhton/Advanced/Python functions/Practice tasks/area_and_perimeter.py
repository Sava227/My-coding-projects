def rectangle():
    length = float(input("Enter the length of the rectangle: "))
    width = float(input("Enter the width of the rectangle: "))
    area = length * width
    perimeter = 2 * (length + width)
    return area, perimeter


area, perimeter = rectangle()
print(f"Area: {area}")
print(f"Perimeter: {perimeter}")
