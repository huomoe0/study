import cv2
import matplotlib.pyplot as plt
import numpy as np

img = cv2.imread(r'./img/Lenna.jpg', cv2.IMREAD_GRAYSCALE)
cv2.imshow('original image', img)
# fil = 1 / 9 * np.array([[1, 1, 1],
#                        [1, 1, 1],  # 设置滤波核
#                        [1, 1, 1]])
# fil = 1 / 10 * np.array([[1, 1, 1],
#                        [1, 2, 1],  # 设置滤波核
#                        [1, 1, 1]])
# fil = 1 / 16 * np.array([[1, 2, 1],
#                         [2, 4, 2],  # 设置滤波核
#                         [1, 2, 1]])
# 使用Opencv的卷积函数
# ImgSmoothed = cv2.filter2D(img, -1, fil, borderType=cv2.BORDER_DEFAULT)

ImgSmoothed = cv2.GaussianBlur(img, (3, 3), 1)
cv2.imshow('Smoothed image', ImgSmoothed)
cv2.waitKey(0)
