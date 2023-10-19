
'''
img1 = img.imread( 'image1' )
#img.imsave(img1)
img.imshow(img1,'dfjkdj')

#img2 = cv.equalizeHist(img1)

gamma = 2.5
img_gamma = np.power(img1 / float(np.max(img1)), gamma)
img_gamma = np.uint8(img_gamma * 255)
img.imshow(img_gamma,'gama')
#img.imshow(img2,'ggggg')
'''