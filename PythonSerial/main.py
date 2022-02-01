# Загрузка интерфеса из Qt Designer
from PyQt5 import QtWidgets, uic
# Связь с Ардуино по Serial ( с помощью библиотеки QSerialPort)
from PyQt5.QtSerialPort import QSerialPort, QSerialPortInfo
from PyQt5.QtCore import QIODevice

app = QtWidgets.QApplication([])
ui = uic.loadUi("Design.ui")
ui.setWindowTitle("SerialGUI")

serial = QSerialPort()
serial.setBaudRate(115200)
portList  = []

ui.show()
app.exec()
