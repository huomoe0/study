

def get_s( r, a, b, c, d ):
    if r < a:
        s = r * c / a
    elif r < b:
        s = c + (r - a) * (d - c) / (b - a)
    else:
        s = d + (r - b) * (255 - d) / (255 - b)
    return s


def dotprocess(img1,img):
    for j in range(img.shape[1]):
        for i in range(img.shape[0]):
            img1[i,j] = get_s(img[i,j], 66, 200, 0, 255)
    return
