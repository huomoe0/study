import numpy as np
import cv2 as cv

def gamma_trans(img, gamma):
    gamma_table = [np.power(x / 255.0, gamma) * 255.0 for x in range(256)]
    gamma_table = np.round(np.array(gamma_table)).astype(np.uint8)
    return cv.LUT(img, gamma_table)

img1 = cv.imread(r'D:/study/python/digit graph/experiment2/img/large.bmp')
img1 = cv.resize(img1, (566, 693))
cv.imshow('window', img1)
cv.waitKey(2000)
img2 = gamma_trans(img1, 0.5)
cv.imshow('window1', img2)
cv.waitKey(2000)
