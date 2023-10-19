import cv2 as cv
import matplotlib.pyplot as plt
import numpy as np


def get_s(r, a, b, c, d):
    if r < a:
        s = r * c / a
    elif r < b:
        s = c + (r - a) * (d - c) / (b - a)
    else:
        s = d + (r - b) * (255 - d) / (255 - b)
    return s


def global_linear_translation(im, c=0, d=255):
    img1 = im.copy()
    maxv = img1.max()
    minv = img1.min()
    if maxv == minv:
        return np.uint8(img1)
    for i in range(img1.shape[0]):
        for j in range(img1.shape[1]):
            img1[i, j] = get_s(img1[i, j], minv, maxv, c, d)
    return np.uint8(img1)


# img = cv.imread(r'D:/study/python/digit graph/experiment2/img/camera1.bmp', cv.IMREAD_GRAYSCALE)
# plt.hist(img.ravel(), 256, (0, 256))
# cv.imshow("img1", img)
# plt.show()

# # 变暗
# img = global_linear_translation(img, 0, 100)
# plt.hist(img.ravel(), 256, (0, 256))
# cv.imshow("img2", img)
# plt.show()

# # 变亮
# img = global_linear_translation(img, 100, 255)
# plt.hist(img.ravel(), 256, (0, 256))
# cv.imshow("img2", img)
# plt.show()

# # 降低对比度
# img = global_linear_translation(img, 80, 200)
# plt.hist(img.ravel(), 256, (0, 256))
# cv.imshow("img2", img)
# plt.show()

# 直方图均衡化
img = cv.imread(r'img/camera1.bmp', cv.IMREAD_GRAYSCALE)
dst = cv.equalizeHist(img)
cv.imshow("hist", dst)
plt.hist(dst, 256, (0, 256))
plt.show()
