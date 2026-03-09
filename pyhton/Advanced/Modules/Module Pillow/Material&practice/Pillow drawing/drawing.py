from PIL import Image
from PIL import ImageDraw

image = Image.new("RGB", (400, 400), "white")
draw = ImageDraw.Draw(image)
draw.rectangle([100, 150, 300, 250], fill = "yellow", outline = "red", width = 3) # it can be draw.ellipse , draw.line
image.show()