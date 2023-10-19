from matplotlib import pyplot as plt
import cv2 as cv
import numpy as np
import os
import win32ui
import space
import zft
import img
import cv2
import numpy as np


#img2 = cv.equalizeHist(img1)


#在HSI空间对亮度分量进行均衡化
def method_one():
    img1 = cv2.imread('../assets/Fig6.png')
    his = cv2.cvtColor(img1, cv2.COLOR_RGB2HLS)
    cv2.imshow('img', img1)
    his_i = his[:, :, 1]
    equal_i = cv2.equalizeHist(his_i)
    his[:, :, 1] = equal_i
    dst = cv2.cvtColor(his, cv2.COLOR_HLS2BGR)
    cv2.imshow('dst', dst)
    cv2.waitKey(0)
    cv2.destroyAllWindows()

#对彩色图像的R，G，B三通道进行均衡化
def method_two():
    img1 = cv2.imread('../assets/Fig6.png')
    (b, g, r) = cv2.split(img1)
    equal_b = cv2.equalizeHist(b)
    equal_g = cv2.equalizeHist(g)
    equal_r = cv2.equalizeHist(r)
    dst = cv2.merge((equal_b, equal_g, equal_r))
    cv2.imshow('img', img1)
    cv2.imshow('dst', dst)
    cv2.waitKey(0)
    cv2.destroyAllWindows()



#对彩色图像进行规定话
#现在有两幅图，FigA 和 FigB，现在要对FigA进行规定化，使FigA 图像的直方图规范化最接近FigB的情况。
def method_three(  ):
    img1 = cv2.imread('../assets/Fig6A.jpg')
    dst = cv2.imread('../assets/Fig6B.jpg')
    def_img = cv2.imread('../assets/Fig6A.jpg')
    color = ('b', 'g', 'r')
    for i, col in enumerate(color):
        hist1, bins = np.histogram(img[:, :, i].ravel(), 256, [0, 256])
        hist2, bins = np.histogram(dst[:, :, i].ravel(), 256, [0, 256])
        # 获得累计直方图
        cdf1 = hist1.cumsum()
        cdf2 = hist2.cumsum()
        # 归一化处理
        cdf1_hist = hist1.cumsum() / cdf1.max()
        cdf2_hist = hist2.cumsum() / cdf2.max()

        # diff_cdf 里是每2个灰度值比率间的差值
        diff_cdf = [[0]*256 for i in range(256)]
        for j in range(256):
            for k in range(256):
                diff_cdf[j][k] = abs(cdf1_hist[j] - cdf2_hist[k])
        # FigA 中的灰度级与目标灰度级的对应表
        lut = np.zeros((256,2), dtype=np.int)
        for j in range(256):
            squ_min = diff_cdf[j][0]
            index = 0
            for k in range(256):
                if squ_min > diff_cdf[j][k]:
                    squ_min = diff_cdf[j][k]
                    index = k
            lut[j] = ([j, index])

        h = int(img.shape[0])
        w = int(dst.shape[1])
        # 对原图像进行灰度值的映射
        for j in range(h):
            for k in range(w):
                def_img[j, k, i] = lut[img[j, k, i]][1]

    cv2.namedWindow('Fig6A', 0)
    cv2.resizeWindow('Fig6A', 400, 520)
    cv2.namedWindow('Fig6B', 0)
    cv2.resizeWindow('Fig6B', 400, 520)
    cv2.namedWindow('def', 0)
    cv2.resizeWindow('def', 400, 520)
    cv2.imshow('Fig6A', img)
    cv2.imshow('Fig6B', dst)
    cv2.imshow('def', def_img)

    cv2.waitKey(0)
    cv2.destroyAllWindows()

'''
   gamma = 0.5
   img_gamma = np.power(img / float(np.max(img)), gamma)
   img_gamma = np.uint8(img_gamma * 255)
'''