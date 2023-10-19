from matplotlib import pyplot as plt
import cv2 as cv
import numpy as np
import os
import win32ui


def imread( window_name ):
    dlg = win32ui.CreateFileDialog(1) # 1表示打开文件对话框
    dlg.DoModal()
    filename = dlg.GetPathName()      # 获取选择的文件名称

    img = cv.imdecode(np.fromfile(os.path.join(filename), dtype=np.uint8), cv.WINDOW_NORMAL)   #读取中、英文路径的文件方法
    cv.namedWindow(window_name, cv.WINDOW_NORMAL)   #这样,窗口"old image"为可调整大小
    cv.imshow(window_name, img)
    return img


def imsave(img):
    dlg = win32ui.CreateFileDialog(0)
    dlg.DoModal()
    filename = dlg.GetPathName()
    cv.imwrite(filename, img)
    return

def imshow(img, window_name ):
    cv.namedWindow(window_name, cv.WINDOW_NORMAL)  # 这样,窗口"old image"为可调整大小
    cv.imshow(window_name, img)
    return
