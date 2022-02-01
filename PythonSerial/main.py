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
#==================================== ВЫВОД ДАННЫХ В ПОРТ ===============================
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

def onRead():
    rx = serial.readLine()            # Возвращает массив байтов
    rxs = str(rx, 'utf-8').strip()    # Переводим в строки (.strip как trim в ардуино, подрезает контрольные символы)
    print(rxs)

def onOpen():                        # Функция открывает порт выбранный в списке Qcombobox
    serial.setPortName(ui.comL.currentText())
    serial.open(QIODevice.ReadWrite)

def onClose():                       # Функция закрывает порт
    serial.close()

serial.readyRead.connect(onRead)     # Читаем входящие данные на порт
ui.openB.clicked.connect(onOpen)     # По нажатию на кнопку вызываем функцию onOpen (Открываем порт)
ui.closeB.clicked.connect(onClose)   # Закрываем порт

ui.show()
app.exec()
#==========================================================================================
