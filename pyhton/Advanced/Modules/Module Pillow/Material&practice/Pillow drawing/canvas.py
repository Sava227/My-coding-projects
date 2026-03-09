from PIL import Image, ImageDraw

# Canvas size
WIDTH, HEIGHT = 600, 600
img = Image.new("RGB", (WIDTH, HEIGHT), "white")
draw = ImageDraw.Draw(img)

# Colors (Mondrian palette)
RED = (220, 30, 30)
BLUE = (30, 60, 200)
YELLOW = (245, 220, 70)
BLACK = (0, 0, 0)
WHITE = (255, 255, 255)

LINE_WIDTH = 12

#Colored rectangles
#Large red rectangle (top-right)
draw.rectangle([200, 0, WIDTH, 350], fill=RED)

#Blue rectangle (bottom-left)
draw.rectangle([0, 350, 200, HEIGHT], fill=BLUE)

#Yellow rectangle (bottom-right small)
draw.rectangle([480, 420, WIDTH, HEIGHT], fill=YELLOW)

#White rectangles are left as background

#Black grid lines
#Vertical lines
draw.line([200, 0, 200, HEIGHT], fill=BLACK, width=LINE_WIDTH)
draw.line([480, 350, 480, HEIGHT], fill=BLACK, width=LINE_WIDTH)

#Horizontal lines
draw.line([0, 350, WIDTH, 350], fill=BLACK, width=LINE_WIDTH)
draw.line([200, 420, WIDTH, 420], fill=BLACK, width=LINE_WIDTH)

#Outer border (optional, Mondrian-style framing)
draw.rectangle(
    [0, 0, WIDTH - 1, HEIGHT - 1],
    outline=BLACK,
    width=LINE_WIDTH
)

#Save and show
img.save("mondrian_composition.png")
img.show()
