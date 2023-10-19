import os
from PyQt5 import QtCore, QtGui, QtWidgets
from PyQt5.QtWidgets import QMessageBox, QFileDialog


class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(454, 404)
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.groupBox = QtWidgets.QGroupBox(self.centralwidget)
        self.groupBox.setGeometry(QtCore.QRect(10, 10, 441, 121))
        self.groupBox.setObjectName("groupBox")

        self.radioButton = QtWidgets.QRadioButton(self.groupBox)
        self.radioButton.setGeometry(QtCore.QRect(20, 20, 91, 21))
        self.radioButton.setObjectName("radioButton")
        self.radioButton.setChecked(True)

        self.radioButton_2 = QtWidgets.QRadioButton(self.groupBox)
        self.radioButton_2.setGeometry(QtCore.QRect(130, 20, 91, 21))
        self.radioButton_2.setObjectName("radioButton_2")
        self.radioButton_3 = QtWidgets.QRadioButton(self.groupBox)
        self.radioButton_3.setGeometry(QtCore.QRect(20, 50, 91, 21))
        self.radioButton_3.setObjectName("radioButton_3")
        self.comboBox = QtWidgets.QComboBox(self.groupBox)
        self.comboBox.setGeometry(QtCore.QRect(70, 80, 81, 22))
        self.comboBox.setObjectName("comboBox")
        self.comboBox.addItem("")
        self.comboBox.addItem("")
        self.label = QtWidgets.QLabel(self.groupBox)
        self.label.setGeometry(QtCore.QRect(13, 80, 61, 20))
        self.label.setObjectName("label")
        self.label_2 = QtWidgets.QLabel(self.groupBox)
        self.label_2.setGeometry(QtCore.QRect(170, 80, 61, 21))
        self.label_2.setObjectName("label_2")
        self.lineEdit = QtWidgets.QLineEdit(self.groupBox)
        self.lineEdit.setGeometry(QtCore.QRect(230, 80, 51, 20))
        self.lineEdit.setObjectName("lineEdit")
        self.label_3 = QtWidgets.QLabel(self.groupBox)
        self.label_3.setGeometry(QtCore.QRect(310, 80, 61, 21))
        self.label_3.setObjectName("label_3")
        self.lineEdit_2 = QtWidgets.QLineEdit(self.groupBox)
        self.lineEdit_2.setGeometry(QtCore.QRect(370, 80, 51, 20))
        self.lineEdit_2.setObjectName("lineEdit_2")
        self.groupBox_2 = QtWidgets.QGroupBox(self.centralwidget)
        self.groupBox_2.setGeometry(QtCore.QRect(10, 140, 441, 241))
        self.groupBox_2.setObjectName("groupBox_2")
        self.lineEdit_3 = QtWidgets.QLineEdit(self.groupBox_2)
        self.lineEdit_3.setGeometry(QtCore.QRect(80, 20, 201, 20))
        self.lineEdit_3.setText("")
        self.lineEdit_3.setObjectName("lineEdit_3")
        self.label_4 = QtWidgets.QLabel(self.groupBox_2)
        self.label_4.setGeometry(QtCore.QRect(20, 20, 61, 21))
        self.label_4.setObjectName("label_4")
        self.pushButton = QtWidgets.QPushButton(self.groupBox_2)
        self.pushButton.setGeometry(QtCore.QRect(290, 20, 61, 23))
        self.pushButton.setObjectName("pushButton")
        self.pushButton_2 = QtWidgets.QPushButton(self.groupBox_2)
        self.pushButton_2.setGeometry(QtCore.QRect(360, 20, 61, 23))
        self.pushButton_2.setObjectName("pushButton_2")

        self.tableWidget = QtWidgets.QTableWidget(self.groupBox_2)
        self.tableWidget.setGeometry(QtCore.QRect(20, 51, 401, 181))
        self.tableWidget.setObjectName("tableWidget")

        MainWindow.setCentralWidget(self.centralwidget)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

        self.pushButton.clicked.connect(self.loadimage)
        self.pushButton_2.clicked.connect(self.execute)

    def execute(self):
        QMessageBox.information(None, "结果", "重命名成功", QMessageBox.Ok)

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

    def loadimage(self):
        try:
            self.path = QFileDialog.getExistingDirectory(None, "选择图片文件夹", os.getcwd())
            self.list = os.listdir(self.path)
            num = 0  # 记录图片数量
            l = []
            for i in range(0, len(self.list)):  # 遍历图片列表
                filepath = os.path.join(self.path, self.list[i])  # 记录遍历到的文件名
                if os.path.isfile(filepath):  # 判断是否为文件
                    imgType = os.path.splitext(filepath)[1]  # 获取扩展名
                    if self.isImg(imgType):  # 判断是否为图片
                        item = QtWidgets.QTableWidgetItem(self.list[i])  # 创建列表项
                        item2 = QtWidgets.QTableWidgetItem(self.path)
                        l.append((item, item2))
                        num += 1  # 数量加1

            self.tableWidget.clear()

            self.tableWidget.resizeColumnsToContents()
            self.tableWidget.setAlternatingRowColors(True)
            self.tableWidget.setColumnCount(2)
            self.tableWidget.setRowCount(num)
            self.tableWidget.setHorizontalHeaderLabels(['图片名', '图片路径'])
            for i in range(0, num):
                self.tableWidget.setItem(i, 0, l[i][0])
                self.tableWidget.setItem(i, 1, l[i][1])
            self.lineEdit_3.setText(self.path)
            self.statusbar.showMessage("共有" + str(num) + "张图片")
        except:
            QMessageBox.warning(None, '警告', '请选择一个有效路径……', QMessageBox.Ok)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "图片批量重命名"))
        self.groupBox.setTitle(_translate("MainWindow", "重命名设置"))
        self.radioButton.setText(_translate("MainWindow", "文件名大写"))
        self.radioButton_2.setText(_translate("MainWindow", "文件名小写"))
        self.radioButton_3.setText(_translate("MainWindow", "文件名编号"))
        self.comboBox.setItemText(0, _translate("MainWindow", "img_***"))
        self.comboBox.setItemText(1, _translate("MainWindow", "file_***"))
        self.label.setText(_translate("MainWindow", "设置模板："))
        self.label_2.setText(_translate("MainWindow", "起始编号："))
        self.lineEdit.setText(_translate("MainWindow", "1"))
        self.label_3.setText(_translate("MainWindow", "编号增量："))
        self.lineEdit_2.setText(_translate("MainWindow", "1"))
        self.groupBox_2.setTitle(_translate("MainWindow", "图片设置"))
        self.label_4.setText(_translate("MainWindow", "起始编号："))
        self.pushButton.setText(_translate("MainWindow", "选择"))
        self.pushButton_2.setText(_translate("MainWindow", "重命名"))
