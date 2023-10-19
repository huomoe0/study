import cv2
import matplotlib.pyplot as plt

# %matplotlib inline
# %config InlinBackend.figure_format = "retina"
plt.rcParams['font.family'] = ['SimHei']
plt.rcParams['axes.unicode_minus'] = False
img_BGR = cv2.imread(r'img/Lenna.jpg')
img_RGB = cv2.cvtColor(img_BGR, cv2.COLOR_BGR2RGB)
plt.imshow(img_RGB)
plt.show()
