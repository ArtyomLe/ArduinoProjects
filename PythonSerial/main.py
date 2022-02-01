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
#======================================== ВКЛЮЧЕНИЕ ДИОДА ===================================
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
    data = rxs.split(',')             # Парсинг (делаем список строковых данных для дальнейшей работы)
    print(data)

def onOpen():                        # Функция открывает порт выбранный в списке Qcombobox
    serial.setPortName(ui.comL.currentText())
    serial.open(QIODevice.ReadWrite)

def serialSend(data):                # Список int (конвертируем численные значения в строку и разделяем запятыми)
    txs = ""
    for val in data:                 # Составляем входящие данные через запятую
        txs += str(val)              # Значения конвертируем в строки
        txs += ','
    txs = txs[:-1]                   # Убираем последнюю запятую (через оператор доступа) в пакете данных и добавляем терминатор ;
    txs += ';'
    serial.write(txs.encode())

def onClose():                       # Функция закрывает порт
    serial.close()

def ledControl(val):
#   if val == 2: val = 1
    serialSend([0, val])

def fanControl(val):
    print(val)

def bulbControl(val):
    print(val)

# Порты
serial.readyRead.connect(onRead)     # Читаем входящие данные на порт
ui.openB.clicked.connect(onOpen)     # По нажатию на кнопку вызываем функцию onOpen (Открываем порт)
ui.closeB.clicked.connect(onClose)   # Закрываем порт

# Checkboxes
ui.ledC.stateChanged.connect(ledControl)       # Чекбокс LED
ui.fanC.stateChanged.connect(fanControl)       # Чекбокс вентилятора
ui.bulbC.stateChanged.connect(bulbControl)     # Чекбокс лампы


ui.show()
app.exec()
# ================================= Слайдеры (RGB) ============================
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
    data = rxs.split(',')             # Парсинг (делаем список строковых данных для дальнейшей работы)
    print(data)

def onOpen():                        # Функция открывает порт выбранный в списке Qcombobox
    serial.setPortName(ui.comL.currentText())
    serial.open(QIODevice.ReadWrite)

def serialSend(data):                # Список int (конвертируем численные значения в строку и разделяем запятыми)
    txs = ""
    for val in data:                 # Составляем входящие данные через запятую
        txs += str(val)              # Значения конвертируем в строки
        txs += ','
    txs = txs[:-1]                   # Убираем последнюю запятую (через оператор доступа) в пакете данных и добавляем терминатор ;
    txs += ';'
    serial.write(txs.encode())

def onClose():                       # Функция закрывает порт
    serial.close()

def ledControl(val):
#   if val == 2: val = 1
    serialSend([0, val])

def fanControl(val):
    serialSend([3, val])

def bulbControl(val):
    serialSend([4, val])

def RGBcontrol():
    serialSend([1, ui.RS.value(), ui.GS.value(), ui.BS.value()])


# Порты
serial.readyRead.connect(onRead)     # Читаем входящие данные на порт
ui.openB.clicked.connect(onOpen)     # По нажатию на кнопку вызываем функцию onOpen (Открываем порт)
ui.closeB.clicked.connect(onClose)   # Закрываем порт

# Checkboxes
ui.ledC.stateChanged.connect(ledControl)       # Чекбокс LED
ui.fanC.stateChanged.connect(fanControl)       # Чекбокс вентилятора
ui.bulbC.stateChanged.connect(bulbControl)     # Чекбокс лампы

# Слайдеры (RGB)
ui.RS.valueChanged.connect(RGBcontrol)
ui.GS.valueChanged.connect(RGBcontrol)
ui.BS.valueChanged.connect(RGBcontrol)

ui.show()
app.exec()
#=======================================SERVO И ОТПРАВКА ТЕКСТА==========================================
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
    data = rxs.split(',')             # Парсинг (делаем список строковых данных для дальнейшей работы)
    print(data)

def onOpen():                        # Функция открывает порт выбранный в списке Qcombobox
    serial.setPortName(ui.comL.currentText())
    serial.open(QIODevice.ReadWrite)

def serialSend(data):                # Список int (конвертируем численные значения в строку и разделяем запятыми)
    txs = ""
    for val in data:                 # Составляем входящие данные через запятую
        txs += str(val)              # Значения конвертируем в строки
        txs += ','
    txs = txs[:-1]                   # Убираем последнюю запятую (через оператор доступа) в пакете данных и добавляем терминатор ;
    txs += ';'
    serial.write(txs.encode())

def onClose():                       # Функция закрывает порт
    serial.close()

def ledControl(val):
#   if val == 2: val = 1
    serialSend([0, val])

def fanControl(val):
    serialSend([3, val])

def bulbControl(val):
    serialSend([4, val])

def RGBcontrol():
    serialSend([1, ui.RS.value(), ui.GS.value(), ui.BS.value()])

def servoControl(val):
    serialSend([2, val])

def sendText():
    txs = "5, "
    txs += ui.textF.displayText()
    txs += ';'
    serial.write(txs.encode())

# Порты
serial.readyRead.connect(onRead)     # Читаем входящие данные на порт
ui.openB.clicked.connect(onOpen)     # По нажатию на кнопку вызываем функцию onOpen (Открываем порт)
ui.closeB.clicked.connect(onClose)   # Закрываем порт

# Checkboxes
ui.ledC.stateChanged.connect(ledControl)       # Чекбокс LED
ui.fanC.stateChanged.connect(fanControl)       # Чекбокс вентилятора
ui.bulbC.stateChanged.connect(bulbControl)     # Чекбокс лампы

# Слайдеры (RGB)
ui.RS.valueChanged.connect(RGBcontrol)
ui.GS.valueChanged.connect(RGBcontrol)
ui.BS.valueChanged.connect(RGBcontrol)

# Servo
ui.servoK.valueChanged.connect(servoControl)

# Отправка текста
ui.sendB.clicked.connect(sendText)

ui.show()
app.exec()
#=================================================================================
