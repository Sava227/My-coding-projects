from PIL import Image, ImageDraw

# 1) Open the image
img = Image.open("cat.png").convert("RGB")
w, h = img.size

draw = ImageDraw.Draw(img)

# 2) Grid settings (change if you want)
step = 120                 # distance between lines (px)
line_color = (60, 60, 60)  # dark gray
line_width = 8

# 3) Vertical lines
for x in range(step, w, step):
    draw.line([(x, 0), (x, h)], fill=line_color, width=line_width)

# 4) Horizontal lines
for y in range(step, h, step):
    draw.line([(0, y), (w, y)], fill=line_color, width=line_width)

# 5) Save and show
img.save("cat_grid.png")
img.show()