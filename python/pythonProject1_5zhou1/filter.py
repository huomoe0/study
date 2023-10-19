import numpy as np

def get_average(i, j, img):
    sum = (img[i - 1, j - 1] + img[i - 1, j] + img[i - 1, j + 1] + img[i, j - 1] + img[i, j] + img[i, j + 1] + img[i + 1, j - 1] + img[i + 1, j] + img[i + 1, j + 1]) / 9
    return sum


def average_filter(img1, img):
    for j in range(1, img.shape[1] - 1, 1):
        for i in range(1, img.shape[0] - 1, 1):
            img1[i, j] = get_average(i, j, img)
    return


def sort(a, n):
    for i in range(n):
        for j in range(i+1, n):
            if a[i] > a[j]:
                a[i], a[j] = a[j], a[i]
    return


def get_middle_3x3(i, j, img):
    a = [0] * 9
    nx, ny = [-1, -1, -1, 0, 0, 0, 1, 1, 1], [-1, 0, 1, -1, 0, 1, -1, 0, 1]
    for _ in range(9):
        a[_] = img[i + nx[_], j + ny[_]]
    sort(a, 9)
    return a[4]


def middle_filter(img):
    img1 = np.zeros(img.shape, np.uint8)
    for j in range(1, img.shape[1]-1, 1):
        for i in range(1, img.shape[0]-1, 1):
            img1[i, j] = get_middle_3x3(i, j, img)
    return img1


def get_sobel(i, j, img):
    dx = img[i-1][j+1] - img[i-1][j-1] + img[i][j+1] - img[i][j-1] + img[i+1][j+1] - img[i+1][j-1]
    dy = img[i+1][j-1] - img[i-1][j-1] + img[i+1][j] - img[i-1][j] + img[i+1][j+1] - img[i-1][j+1]
    return abs(dx) + abs(dy)


def sobel(img):
    img1 = np.zeros(img.shape, np.uint8)
    for i in range(1, img.shape[0]-1):
        for j in range(1, img.shape[1]-1):
            img1[i, j] = get_sobel(i, j, img)
    return img1



def get_image0_255(img):
    img1 = np.zeros(img.shape, np.uint8)
    a = np.min(img)
    b = np.max(img)
    for i in range(1, img.shape[0]-1):
        for j in range(1, img.shape[1]-1):
            img1[i, j] = np.uint8((img[i, j] - a) * 255 / (b-a))
    return img1


def get_laplace(i, j, img):
    d = img[i-1][j] + img[i+1][j] + img[i][j-1] + img[i][j+1] - 4 * img[i][j]
    return d

def laplace(img):
    img1 = np.zeros(img.shape, np.int32)
    for i in range(1, img.shape[0]-1):
        for j in range(1, img.shape[1]-1):
            img1[i, j] = get_laplace(i, j, img)
    img2 = get_image0_255(img1)
    return img2


