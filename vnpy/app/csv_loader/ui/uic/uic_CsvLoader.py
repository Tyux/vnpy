# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file '.\vnpy\app\csv_loader\ui\CsvLoader.ui'
#
# Created by: PyQt5 UI code generator 5.11.3
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_CsvLoader(object):
    def setupUi(self, CsvLoader):
        CsvLoader.setObjectName("CsvLoader")
        self.verticalLayout = QtWidgets.QVBoxLayout(CsvLoader)
        self.verticalLayout.setObjectName("verticalLayout")
        self.horizontalLayout = QtWidgets.QHBoxLayout()
        self.horizontalLayout.setObjectName("horizontalLayout")
        self.choose_button = QtWidgets.QPushButton(CsvLoader)
        self.choose_button.setObjectName("choose_button")
        self.horizontalLayout.addWidget(self.choose_button)
        self.file_edit = QtWidgets.QLineEdit(CsvLoader)
        self.file_edit.setObjectName("file_edit")
        self.horizontalLayout.addWidget(self.file_edit)
        self.verticalLayout.addLayout(self.horizontalLayout)
        self.formLayout = QtWidgets.QFormLayout()
        self.formLayout.setObjectName("formLayout")
        self.label_8 = QtWidgets.QLabel(CsvLoader)
        self.label_8.setObjectName("label_8")
        self.formLayout.setWidget(0, QtWidgets.QFormLayout.FieldRole, self.label_8)
        self.label_9 = QtWidgets.QLabel(CsvLoader)
        self.label_9.setObjectName("label_9")
        self.formLayout.setWidget(1, QtWidgets.QFormLayout.LabelRole, self.label_9)
        self.symbol_edit = QtWidgets.QLineEdit(CsvLoader)
        self.symbol_edit.setObjectName("symbol_edit")
        self.formLayout.setWidget(1, QtWidgets.QFormLayout.FieldRole, self.symbol_edit)
        self.label_11 = QtWidgets.QLabel(CsvLoader)
        self.label_11.setObjectName("label_11")
        self.formLayout.setWidget(3, QtWidgets.QFormLayout.LabelRole, self.label_11)
        self.interval_combo = QtWidgets.QComboBox(CsvLoader)
        self.interval_combo.setObjectName("interval_combo")
        self.formLayout.setWidget(3, QtWidgets.QFormLayout.FieldRole, self.interval_combo)
        self.label = QtWidgets.QLabel(CsvLoader)
        self.label.setObjectName("label")
        self.formLayout.setWidget(4, QtWidgets.QFormLayout.FieldRole, self.label)
        self.label_2 = QtWidgets.QLabel(CsvLoader)
        self.label_2.setObjectName("label_2")
        self.formLayout.setWidget(5, QtWidgets.QFormLayout.LabelRole, self.label_2)
        self.datetime_edit = QtWidgets.QLineEdit(CsvLoader)
        self.datetime_edit.setObjectName("datetime_edit")
        self.formLayout.setWidget(5, QtWidgets.QFormLayout.FieldRole, self.datetime_edit)
        self.label_3 = QtWidgets.QLabel(CsvLoader)
        self.label_3.setObjectName("label_3")
        self.formLayout.setWidget(6, QtWidgets.QFormLayout.LabelRole, self.label_3)
        self.open_edit = QtWidgets.QLineEdit(CsvLoader)
        self.open_edit.setObjectName("open_edit")
        self.formLayout.setWidget(6, QtWidgets.QFormLayout.FieldRole, self.open_edit)
        self.label_4 = QtWidgets.QLabel(CsvLoader)
        self.label_4.setObjectName("label_4")
        self.formLayout.setWidget(7, QtWidgets.QFormLayout.LabelRole, self.label_4)
        self.high_edit = QtWidgets.QLineEdit(CsvLoader)
        self.high_edit.setObjectName("high_edit")
        self.formLayout.setWidget(7, QtWidgets.QFormLayout.FieldRole, self.high_edit)
        self.label_5 = QtWidgets.QLabel(CsvLoader)
        self.label_5.setObjectName("label_5")
        self.formLayout.setWidget(8, QtWidgets.QFormLayout.LabelRole, self.label_5)
        self.low_edit = QtWidgets.QLineEdit(CsvLoader)
        self.low_edit.setObjectName("low_edit")
        self.formLayout.setWidget(8, QtWidgets.QFormLayout.FieldRole, self.low_edit)
        self.label_6 = QtWidgets.QLabel(CsvLoader)
        self.label_6.setObjectName("label_6")
        self.formLayout.setWidget(9, QtWidgets.QFormLayout.LabelRole, self.label_6)
        self.close_edit = QtWidgets.QLineEdit(CsvLoader)
        self.close_edit.setObjectName("close_edit")
        self.formLayout.setWidget(9, QtWidgets.QFormLayout.FieldRole, self.close_edit)
        self.label_7 = QtWidgets.QLabel(CsvLoader)
        self.label_7.setObjectName("label_7")
        self.formLayout.setWidget(10, QtWidgets.QFormLayout.LabelRole, self.label_7)
        self.volume_edit = QtWidgets.QLineEdit(CsvLoader)
        self.volume_edit.setObjectName("volume_edit")
        self.formLayout.setWidget(10, QtWidgets.QFormLayout.FieldRole, self.volume_edit)
        self.label_12 = QtWidgets.QLabel(CsvLoader)
        self.label_12.setObjectName("label_12")
        self.formLayout.setWidget(2, QtWidgets.QFormLayout.LabelRole, self.label_12)
        self.exchange_combo = QtWidgets.QComboBox(CsvLoader)
        self.exchange_combo.setObjectName("exchange_combo")
        self.formLayout.setWidget(2, QtWidgets.QFormLayout.FieldRole, self.exchange_combo)
        self.verticalLayout.addLayout(self.formLayout)
        self.load_button = QtWidgets.QPushButton(CsvLoader)
        self.load_button.setObjectName("load_button")
        self.verticalLayout.addWidget(self.load_button)

        self.retranslateUi(CsvLoader)
        QtCore.QMetaObject.connectSlotsByName(CsvLoader)

    def retranslateUi(self, CsvLoader):
        _translate = QtCore.QCoreApplication.translate
        CsvLoader.setWindowTitle(_translate("CsvLoader", "Csv载入器"))
        self.choose_button.setText(_translate("CsvLoader", "选择文件"))
        self.label_8.setText(_translate("CsvLoader", "合约信息"))
        self.label_9.setText(_translate("CsvLoader", "Symbol"))
        self.label_11.setText(_translate("CsvLoader", "Interval"))
        self.label.setText(_translate("CsvLoader", "表头属性"))
        self.label_2.setText(_translate("CsvLoader", "Datetime"))
        self.datetime_edit.setText(_translate("CsvLoader", "Datetime"))
        self.label_3.setText(_translate("CsvLoader", "Open"))
        self.open_edit.setText(_translate("CsvLoader", "Open"))
        self.label_4.setText(_translate("CsvLoader", "High"))
        self.high_edit.setText(_translate("CsvLoader", "High"))
        self.label_5.setText(_translate("CsvLoader", "Low"))
        self.low_edit.setText(_translate("CsvLoader", "Low"))
        self.label_6.setText(_translate("CsvLoader", "Close"))
        self.close_edit.setText(_translate("CsvLoader", "Close"))
        self.label_7.setText(_translate("CsvLoader", "Volume"))
        self.volume_edit.setText(_translate("CsvLoader", "Volume"))
        self.label_12.setText(_translate("CsvLoader", "Exchange"))
        self.load_button.setText(_translate("CsvLoader", "载入"))


if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    CsvLoader = QtWidgets.QDialog()
    ui = Ui_CsvLoader()
    ui.setupUi(CsvLoader)
    CsvLoader.show()
    sys.exit(app.exec_())

