
from matplotlib import pyplot as plt


def tongji(a,img):
    for i in range(256):
        a[i] = 0
    for j in range(img.shape[1]):
        for i in range(img.shape[0]):
            b = img[i,j]
            a[b] = a[b]+1
    return


def showzft(img):
    plt.hist(img.ravel(), 256, [0, 256], )
    plt.show()
