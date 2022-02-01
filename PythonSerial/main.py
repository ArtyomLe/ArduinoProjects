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
#======================================================================
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

ports = QSerialPortInfo().availablePorts()
for port in ports:
    portList.append(port.portName())

ui.comL.addItems(portList)   # Выводим список портов в окне приложения

ui.show()
app.exec()
#====================================== ОТКРЫВАЕМ ПОРТ =============================
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

ports = QSerialPortInfo().availablePorts()
for port in ports:
    portList.append(port.portName())
ui.comL.addItems(portList)           # Выводим список портов в окне приложения

def onOpen():                        # Функция открывает порт выбранный в списке Qcombobox 
    serial.setPortName(ui.comL.currentText())
    serial.open(QIODevice.ReadWrite)

ui.openB.clicked.connect(onOpen)     # По нажатию на кнопку вызываем функцию onOpen

ui.show()
app.exec()
#====================================================================================================
