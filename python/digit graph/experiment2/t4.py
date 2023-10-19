import random
import cv2
import numpy as np
import matplotlib.pyplot as plt


def addSaltAndPepper(src, percentage):
    NoiseImg = src.copy()
    NoiseNum = int(percentage * src.shape[0] * src.shape[1])
    for i in range(NoiseNum):
        randX = random.randint(0, src.shape[0] - 1)
        randY = random.randint(0, src.shape[1] - 1)
        if random.randint(0, 1) == 0:
            NoiseImg[randX, randY] = 0
        else:
            NoiseImg[randX, randY] = 255
    return NoiseImg

def addGaussianNoise(src, means, sigma):
    NoiseImg = src / src.max()
    rows = NoiseImg.shape[0]
    cols = NoiseImg.shape[1]
    for i in range(rows):
        for j in range(cols):
            # Python里使用random.gauss函数加高斯噪声
            NoiseImg[i, j] = NoiseImg[i, j] + random.gauss(means, sigma)
            if NoiseImg[i, j] < 0:
                NoiseImg[i, j] = 0
            elif NoiseImg[i, j] > 1:
                NoiseImg[i, j] = 1
    NoiseImg = np.uint8(NoiseImg * 255)
    return NoiseImg

img1 = cv2.imread('img/camera1.bmp ')
img1 = cv2.cvtColor(img1, cv2.COLOR_BGR2GRAY)
# cv2.imshow('window1', img1)
img2 = addSaltAndPepper(img1, 0.05)

# img2 = addGaussianNoise(img1, 0, 0.1)

# img2 = addSaltAndPepper(img1, 0.05)
# cv2.imshow('window2', img2)
plt.imshow(img2, vmin=0, vmax=255, cmap=plt.cm.gray)
plt.show()
# img3 = cv2.blur(img2, (3, 3)) # 均值滤波
# img3 = cv2.medianBlur(img2, 3) # 中值滤波
# img3 = cv2.GaussianBlur(img2, (3, 3), 1) # 高斯滤波
# cv2.imshow('window3',  img3)

cv2.waitKey()
