import cv2
import numpy as np

img = cv2.imread(r'./img/Lenna.jpg', cv2.IMREAD_GRAYSCALE)
cv2.imshow('original image', img)
fil = np.array([[0, 1, 0],
               [1, -4, 1],  # 设置滤波核
               [0, 1, 0]])
# fil = np.array([[0, -1, 0],
#                [-1, 5, -1],  # 设置滤波核
#                [0, -1, 0]])
# 使用Opencv的卷积函数
ImgSmoothed = cv2.filter2D(img, -1, fil, borderType=cv2.BORDER_DEFAULT)
cv2.imshow('Smoothed image', ImgSmoothed)
cv2.waitKey(0)
