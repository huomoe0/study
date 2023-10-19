from matplotlib import pyplot as plt
import cv2 as cv
import numpy as np
import os
import win32ui
import space
import zft
import img
import filter

# img1 = img.imread( 'image1' )
# img2 = np.zeros( img1.shape, np.uint8)
# filter.average_filter( img2, img1 )
# img.imshow(img2,'image2')
# cv.waitKey(0)
# cv.destroyAllWindows()


# img1 = img.imread('image1')
# img2 = filter.middle_filter(img1)
# img.imshow(img2, 'image')
# cv.waitKey(0)
# cv.destroyAllWindows()

# img1 = img.imread('image1')
# img2 = filter.sobel(img1)
# img.imshow(img2, 'image')
# cv.waitKey(0)
# cv.destroyAllWindows()

img1 = img.imread('image1')
img2 = filter.laplace(img1)
img.imshow(img2, 'image')
cv.waitKey(0)
cv.destroyAllWindows()

'''
img1 = img.imread( 'image1' )
img2 = cv.equalizeHist(img1)
img.imshow(img2,'image_1')
zft.showzft(img1)
zft.showzft(img2)
cv.waitKey(0)
cv.destroyAllWindows()
'''

'''
img1 = img.imread( 'image1' )
img_gamma = np.power( img1 / float(np.max(img1)), 2.5 )
img_gamma = np.uint8(img_gamma * 255)
img.imshow(img_gamma,'gama')
cv.waitKey(0)
cv.destroyAllWindows()
'''



'''
#img.imshow(img1,'image_0')
gamma = 2.5
img_gamma = np.power(img1 / float(np.max(img1)), gamma)
img_gamma = np.uint8(img_gamma * 255)
img.imshow(img_gamma,'gama')
#img.imshow(img2,'ggggg')


zft.showzft(img1)

a = [0]*256
zft.tongji(a,img1)

img2 = np.zeros( img1.shape, np.uint8)
space.dotprocess( img2, img1 )
img.imshow(img2,'dfsfffff')
zft.showzft(img2)

opencv_python-4.8.1.78-cp37-abi3-win_amd64.whl
'''
