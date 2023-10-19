from PyQt5 import QtCore, QtGui, QtWidgets
from rename import Ui_MainWindow as Ui_MainWindow

# 主方法，程序从此处启动PyQt设计的窗体
if __name__ == '__main__':
    import sys
    app = QtWidgets.QApplication(sys.argv)
    # app.setStyle("Fusion")

    MainWindow = QtWidgets.QMainWindow()

    ui = Ui_MainWindow()
    ui.setupUi(MainWindow)

    MainWindow.show()
    sys.exit(app.exec_())
