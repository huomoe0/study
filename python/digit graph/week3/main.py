import cv2 as cv
import numpy as np

from matplotlib import pyplot as plt

img = cv.imread('img/Lenna.bmp')
plt.hist(img.ravel(), 256, (0, 256), )
plt.show()
cv.imshow("kjj", img)

for i in range(100):
    for j in range(100):
        img[i][j] = 222
cv.imshow("kjjjj", img)

cv.waitKey(0)
cv.destroyAllWindows()
