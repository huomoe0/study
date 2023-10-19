import os
from PyQt5 import QtCore, QtGui, QtWidgets
from PyQt5.QtGui import QFontMetrics, QFontInfo
from PyQt5.QtWidgets import QFileDialog, QMessageBox, QFontDialog


class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(585, 428)
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.listWidget = QtWidgets.QListWidget(self.centralwidget)
        self.listWidget.setGeometry(QtCore.QRect(0, 0, 141, 371))
        self.listWidget.setObjectName("listWidget")
        self.pushButton = QtWidgets.QPushButton(self.centralwidget)
        self.pushButton.setGeometry(QtCore.QRect(140, 0, 75, 23))
        self.pushButton.setObjectName("pushButton")
        self.groupBox = QtWidgets.QGroupBox(self.centralwidget)
        self.groupBox.setGeometry(QtCore.QRect(150, 30, 431, 121))
        self.groupBox.setObjectName("groupBox")
        self.radioButton = QtWidgets.QRadioButton(self.groupBox)
        self.radioButton.setGeometry(QtCore.QRect(20, 20, 101, 20))
        self.radioButton.setChecked(True)
        self.radioButton.setObjectName("radioButton")
        self.radioButton_2 = QtWidgets.QRadioButton(self.groupBox)
        self.radioButton_2.setGeometry(QtCore.QRect(20, 60, 101, 16))
        self.radioButton_2.setObjectName("radioButton_2")
        self.label = QtWidgets.QLabel(self.groupBox)
        self.label.setGeometry(QtCore.QRect(30, 40, 54, 12))
        self.label.setObjectName("label")
        self.lineEdit = QtWidgets.QLineEdit(self.groupBox)
        self.lineEdit.setGeometry(QtCore.QRect(90, 40, 231, 20))
        self.lineEdit.setObjectName("lineEdit")
        self.pushButton_2 = QtWidgets.QPushButton(self.groupBox)
        self.pushButton_2.setGeometry(QtCore.QRect(330, 40, 75, 23))
        self.pushButton_2.setObjectName("pushButton_2")
        self.pushButton_3 = QtWidgets.QPushButton(self.groupBox)
        self.pushButton_3.setGeometry(QtCore.QRect(330, 80, 75, 23))
        self.pushButton_3.setObjectName("pushButton_3")
        self.lineEdit_2 = QtWidgets.QLineEdit(self.groupBox)
        self.lineEdit_2.setGeometry(QtCore.QRect(90, 80, 231, 20))
        self.lineEdit_2.setText("")
        self.lineEdit_2.setObjectName("lineEdit_2")
        self.label_2 = QtWidgets.QLabel(self.groupBox)
        self.label_2.setGeometry(QtCore.QRect(30, 80, 54, 12))
        self.label_2.setObjectName("label_2")
        self.groupBox_2 = QtWidgets.QGroupBox(self.centralwidget)
        self.groupBox_2.setGeometry(QtCore.QRect(150, 160, 431, 91))
        self.groupBox_2.setObjectName("groupBox_2")
        self.horizontalSlider = QtWidgets.QSlider(self.groupBox_2)
        self.horizontalSlider.setGeometry(QtCore.QRect(90, 40, 160, 22))
        self.horizontalSlider.setMinimum(1)
        self.horizontalSlider.setMaximum(10)
        self.horizontalSlider.setOrientation(QtCore.Qt.Horizontal)
        self.horizontalSlider.setObjectName("horizontalSlider")
        self.label_3 = QtWidgets.QLabel(self.groupBox_2)
        self.label_3.setGeometry(QtCore.QRect(20, 50, 54, 12))
        self.label_3.setObjectName("label_3")
        self.label_4 = QtWidgets.QLabel(self.groupBox_2)
        self.label_4.setGeometry(QtCore.QRect(260, 50, 54, 12))
        self.label_4.setObjectName("label_4")
        self.comboBox = QtWidgets.QComboBox(self.groupBox_2)
        self.comboBox.setGeometry(QtCore.QRect(320, 40, 81, 22))
        self.comboBox.setObjectName("comboBox")
        self.comboBox.addItem("")
        self.comboBox.addItem("")
        self.comboBox.addItem("")
        self.comboBox.addItem("")
        self.comboBox.addItem("")
        self.groupBox_3 = QtWidgets.QGroupBox(self.centralwidget)
        self.groupBox_3.setGeometry(QtCore.QRect(150, 260, 431, 81))
        self.groupBox_3.setObjectName("groupBox_3")
        self.label_5 = QtWidgets.QLabel(self.groupBox_3)
        self.label_5.setGeometry(QtCore.QRect(20, 50, 54, 12))
        self.label_5.setObjectName("label_5")
        self.lineEdit_3 = QtWidgets.QLineEdit(self.groupBox_3)
        self.lineEdit_3.setGeometry(QtCore.QRect(90, 50, 211, 20))
        self.lineEdit_3.setObjectName("lineEdit_3")
        self.pushButton_4 = QtWidgets.QPushButton(self.groupBox_3)
        self.pushButton_4.setGeometry(QtCore.QRect(320, 50, 75, 23))
        self.pushButton_4.setObjectName("pushButton_4")
        self.pushButton_5 = QtWidgets.QPushButton(self.centralwidget)
        self.pushButton_5.setGeometry(QtCore.QRect(470, 350, 75, 23))
        self.pushButton_5.setObjectName("pushButton_5")
        MainWindow.setCentralWidget(self.centralwidget)

        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

        self.pushButton.clicked.connect(self.loadimage)
        self.pushButton_2.clicked.connect(self.setFont)
        self.pushButton_4.clicked.connect(self.setSaveDir)
        self.pushButton_3.clicked.connect(self.setImage)
        self.pushButton_5.clicked.connect(self.execute)

    def execute(self):
        QMessageBox.information(None, "执行结果", "执行成功", QMessageBox.Ok)
    def setImage(self):
        try:
            self.filename = QFileDialog.getOpenFileName(None, "选择图片", "C:/","图片文件(*.jpeg;*.png;*.jpg;*.bmp)")
            # print(self.filename)
            self.lineEdit_2.setText(self.filename[0])
        except Exception as e:
            print(e)

    def setSaveDir(self):
        try:
            self.save_path = QFileDialog.getExistingDirectory(None, "选择保存路径", os.getcwd())
            self.lineEdit_3.setText(self.save_path)
        except Exception as e:
            print(e)


    def setFont(self):
        self.waterfont, ok = QFontDialog.getFont()  # 显示字体对话框
        if ok:  # 判断是否选择了字体
            self.lineEdit.setFont(self.waterfont)  # 设置水印文字的字体
            self.fontSize = QFontMetrics(self.waterfont) # 获取字体尺寸
            self.fontInfo = QFontInfo(self.waterfont) # 获取字体信息


    def loadimage(self):
        try:
            self.path = QFileDialog.getExistingDirectory(None, "选择图片文件夹", os.getcwd())
            self.list = os.listdir(self.path)
            num = 0  # 记录图片数量

            self.listWidget.clear()

            for i in range(0, len(self.list)):  # 遍历图片列表
                filepath = os.path.join(self.path, self.list[i])  # 记录遍历到的文件名
                if os.path.isfile(filepath):  # 判断是否为文件
                    imgType = os.path.splitext(filepath)[1]  # 获取扩展名
                    if self.isImg(imgType):  # 判断是否为图片
                        num += 1  # 数量加1
                        self.item = QtWidgets.QListWidgetItem(self.listWidget)  # 创建列表项
                        self.item.setText(self.list[i])  # 显示图片列表
            self.statusbar.showMessage("共有" + str(num) + "张图片")
        except:
            QMessageBox.warning(None, '警告', '请选择一个有效路径……', QMessageBox.Ok)

    # 是否为图片
    def isImg(self, file):
        file = file.lower()
        if file == '.jpg':
            return True
        elif file == '.png':
            return True
        elif file == '.jpeg':
            return True
        elif file == '.bmp':
            return True
        else:
            return False

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "图片批量添加水印"))
        self.pushButton.setText(_translate("MainWindow", "加载图片"))
        self.groupBox.setTitle(_translate("MainWindow", "水印设置"))
        self.radioButton.setText(_translate("MainWindow", "添加文字水印"))
        self.radioButton_2.setText(_translate("MainWindow", "添加图片水印"))
        self.label.setText(_translate("MainWindow", "打印文字："))
        self.pushButton_2.setText(_translate("MainWindow", "字体设置"))
        self.pushButton_3.setText(_translate("MainWindow", "浏览"))
        self.label_2.setText(_translate("MainWindow", "水印图片："))
        self.groupBox_2.setTitle(_translate("MainWindow", "透明度及位置设置"))
        self.label_3.setText(_translate("MainWindow", "透明度："))
        self.label_4.setText(_translate("MainWindow", "水印位置："))
        self.comboBox.setItemText(0, _translate("MainWindow", "左上角"))
        self.comboBox.setItemText(1, _translate("MainWindow", "右下角"))
        self.comboBox.setItemText(2, _translate("MainWindow", "左下角"))
        self.comboBox.setItemText(3, _translate("MainWindow", "右下角"))
        self.comboBox.setItemText(4, _translate("MainWindow", "居中位置"))
        self.groupBox_3.setTitle(_translate("MainWindow", "路径设置"))
        self.label_5.setText(_translate("MainWindow", "保存位置："))
        self.pushButton_4.setText(_translate("MainWindow", "浏览"))
        self.pushButton_5.setText(_translate("MainWindow", "执行"))
