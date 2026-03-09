from PIL import Image

im = Image.open("task2.jpg")
w, h = im.size
half_w, half_h = w // 2, h // 2

q1 = im.crop((0, 0, half_w, half_h))       # top-left
q2 = im.crop((half_w, 0, w, half_h))       # top-right
q3 = im.crop((0, half_h, half_w, h))       # bottom-left
q4 = im.crop((half_w, half_h, w, h))       # bottom-right

q1 = q1.rotate(90)
q2 = q2.rotate(180)
q3 = q3.rotate(180)
q4 = q4.rotate(270)
res = Image.new("RGB", (w, h))
res.paste(q1, (0, 0))
res.paste(q2, (half_w, 0))
res.paste(q3, (0, half_h))
res.paste(q4, (half_w, half_h))


res.show()
res.save("task2_fixed.jpg")