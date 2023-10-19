import matplotlib.pyplot as plt
import math
import numpy as np


def createBox():
    box = np.zeros((100, 100), np.uint8) + 50
    print(type(box))
    shape = box.shape
    for i in range(shape[0]):
        for j in range(shape[1]):
            if j in range(0, 54) and i in range(50 - int(math.sqrt(729 - (j - 27) ** 2)), 50 + int(math.sqrt(729 - (j - 27) ** 2))):
                box[i, j] = 0
            else:
                box[i, j] = 255
            if j in range(46, 100) and i in range(23, 77):
                box[i, j] = 190
    return box


def histogram(image):
    row, col = image.shape
    hist = [0] * 256
    for i in range(row):
        for j in range(col):
            hist[image[i, j]] += 1

    return hist


image0 = createBox()
plt.figure()  # 创建图像
plt.subplot(1, 2, 1)  # 创建子图
plt.imshow(image0, vmin=0, vmax=255, cmap=plt.cm.gray)
plt.title('ideal image')
image_hist0 = histogram(image0)
plt.subplot(1, 2, 2)
plt.bar(range(256), image_hist0)
plt.show()
