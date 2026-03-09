from PIL import Image

im1 = Image.open("cat.jpg")
im2 = Image.open("flashback.jpg")

w, h = im1.width, im1.height
im2 = im2.resize((w, h), Image.Resampling.LANCZOS)

res = Image.blend(im1, im2, 0.25)

res.show()
res.save("blend_result.jpg")



