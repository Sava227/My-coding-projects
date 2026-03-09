from PIL import Image, ImageDraw

def kandinsky_fragment(size=700, scale=4, out="kandinsky_fragment.png"):
    W = H = size * scale

    BG    = (55, 130, 95)
    ORNG  = (205, 140, 60)
    PALE  = (220, 230, 235)
    BEIGE = (238, 222, 170)
    PINK  = (210, 160, 170)
    LINE  = (80, 70, 65)
    BLACK = (20, 20, 20)

    TEAL  = (25, 95, 90)
    RED1  = (175, 55, 55)
    RED2  = (130, 35, 45)
    REDSM = (185, 70, 65)

    img = Image.new("RGB", (W, H), BG)
    d = ImageDraw.Draw(img)

    cx = int(W * 0.58)
    cy = int(H * 0.44)
    R  = int(W * 0.29)

    rx = R
    ry = int(R * 1.02)
    main_bbox = (cx - rx, cy - ry, cx + rx, cy + ry)

    split_x = int(cx - 0.18 * rx)
    strip_w = int(0.14 * rx)
    strip_x0 = split_x - strip_w
    strip_x1 = split_x

    d.ellipse(main_bbox, fill=PALE)
    d.rectangle((0, 0, split_x, H), fill=BG)
    d.ellipse(main_bbox, fill=PALE)

    left_shift = int(0.18 * rx)
    up_shift   = int(0.05 * ry)
    left_bbox = (cx - rx - left_shift, cy - ry - up_shift, cx + rx - left_shift, cy + ry - up_shift)
    d.ellipse(left_bbox, fill=ORNG)
    d.rectangle((split_x + 2, 0, W, H), fill=BG)

    d.ellipse(main_bbox, fill=PALE)
    d.rectangle((0, 0, split_x, H), fill=BG)
    d.ellipse(main_bbox, fill=PALE)

    y_line = int(cy + 0.04 * ry)
    d.pieslice(main_bbox, start=270, end=360, fill=PINK)

    d.rectangle((strip_x0, cy - ry, strip_x1, cy + ry), fill=BEIGE)
    d.line((strip_x0, cy - ry, strip_x0, cy + ry), fill=LINE, width=max(1, scale))
    d.line((strip_x1, cy - ry, strip_x1, cy + ry), fill=LINE, width=max(2, scale))

    d.line((strip_x1, y_line, cx + rx, y_line), fill=LINE, width=max(2, 2*scale))

    d.rectangle((strip_x1 - int(0.05*rx), cy + int(0.42*ry), strip_x1 + int(0.06*rx), cy + int(0.66*ry)), fill=REDSM)
    d.rectangle((strip_x1 + int(0.02*rx), cy + int(0.58*ry), strip_x1 + int(0.08*rx), cy + int(0.72*ry)), fill=RED1)

    eye_x = int(cx + 0.30 * rx)
    eye_y = int(cy - 0.10 * ry)
    eye_r = int(0.035 * rx)
    d.ellipse((eye_x - eye_r, eye_y - eye_r, eye_x + eye_r, eye_y + eye_r), fill=BLACK)

    bars_x0 = int(cx - 0.70 * rx)
    bars_x1 = int(cx - 0.18 * rx)
    by = int(cy + 0.60 * ry)
    bh = int(0.06 * ry)
    lw = max(1, scale)

    d.rectangle((bars_x0, by, bars_x1, by + bh), fill=TEAL, outline=BLACK, width=lw)
    d.rectangle((bars_x0 + int(0.12*rx), by + int(0.12*ry), bars_x1, by + int(0.12*ry) + bh), fill=RED1, outline=BLACK, width=lw)
    d.rectangle((bars_x0 + int(0.24*rx), by + int(0.24*ry), bars_x1, by + int(0.24*ry) + bh), fill=RED2, outline=BLACK, width=lw)

    img_small = img.resize((size, size), Image.Resampling.LANCZOS)
    img_small.save(out)
    img_small.show()

kandinsky_fragment()
