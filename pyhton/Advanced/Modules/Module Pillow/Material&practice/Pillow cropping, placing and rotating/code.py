from PIL import Image
image = Image.open("cat.jpg")
image.show()
w = image.width
h = image.height
image.thumbnail((128, 128))
image.save('cat-small.jpg')