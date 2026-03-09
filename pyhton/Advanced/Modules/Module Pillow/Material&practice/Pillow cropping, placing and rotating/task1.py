from PIL import Image

img = Image.open("task1.jpg").convert("RGB")
for w, h in [(1024, 768), (600, 400), (100, 100)]:
    im = img.copy()
    im.thumbnail((w, h))
    im.save(f"pic-{w}x{h}.jpg")