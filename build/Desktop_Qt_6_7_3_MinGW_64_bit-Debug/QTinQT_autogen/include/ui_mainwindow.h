/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCharts/QChartView>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *moneytab;
    QTableWidget *wagesTable;
    QPushButton *deleteWageButton;
    QFrame *wagesFrame;
    QPushButton *wagesAddButton;
    QLabel *label;
    QLabel *label_8;
    QLineEdit *wagesLine1;
    QLineEdit *wagesLine2;
    QLabel *label_9;
    QDateEdit *dateEdit_2;
    QDateEdit *dateWages;
    QWidget *expenseTab;
    QPushButton *deleteExpenseButton;
    QTableWidget *tableWidget;
    QFrame *wagesFrame_2;
    QPushButton *expensesAddButton_clicked;
    QLineEdit *lineEdit_4;
    QLabel *label_5;
    QLabel *label_4;
    QLineEdit *txtFirstNum_2;
    QLabel *label_6;
    QComboBox *comboBox;
    QDateEdit *dateEdit;
    QWidget *budgetTab;
    QFrame *frame;
    QChartView *chartView;
    QTableWidget *tableBudget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1308, 839);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/images/pink_pig.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setAutoFillBackground(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        centralwidget->setStyleSheet(QString::fromUtf8("background-color: #ECEEF1;\n"
"color: #1E1E1E;"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(10, 0, 1291, 811));
        tabWidget->setStyleSheet(QString::fromUtf8("QTabWidget::pane {\n"
"    border: none;\n"
"}\n"
"\n"
"QTabBar::tab {\n"
"    background: #F5F6F8;\n"
"    color: #1E1E1E;\n"
"    padding: 8px 16px;\n"
"    border-top-left-radius: 6px;\n"
"    border-top-right-radius: 6px;\n"
"    margin-right: 2px;\n"
"}\n"
"\n"
"QTabBar::tab:hover {\n"
"    background: #E5E7EB;\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"    background: #D1D5DB;     /* Darker active tab */\n"
"    color: #111827;\n"
"    font-weight: 600;\n"
"}"));
        moneytab = new QWidget();
        moneytab->setObjectName("moneytab");
        wagesTable = new QTableWidget(moneytab);
        if (wagesTable->columnCount() < 3)
            wagesTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        wagesTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        wagesTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        wagesTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        wagesTable->setObjectName("wagesTable");
        wagesTable->setGeometry(QRect(270, 50, 301, 191));
        wagesTable->setAlternatingRowColors(true);
        wagesTable->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
        wagesTable->setGridStyle(Qt::PenStyle::SolidLine);
        deleteWageButton = new QPushButton(moneytab);
        deleteWageButton->setObjectName("deleteWageButton");
        deleteWageButton->setGeometry(QRect(270, 260, 131, 41));
        QFont font;
        font.setBold(true);
        deleteWageButton->setFont(font);
        deleteWageButton->setMouseTracking(false);
        wagesFrame = new QFrame(moneytab);
        wagesFrame->setObjectName("wagesFrame");
        wagesFrame->setGeometry(QRect(10, 30, 591, 291));
        wagesFrame->setStyleSheet(QString::fromUtf8("background-color: #FFFFFF;\n"
"border-radius: 8px;\n"
"border: 1px solid #D0D3D8;"));
        wagesFrame->setFrameShape(QFrame::Shape::StyledPanel);
        wagesFrame->setFrameShadow(QFrame::Shadow::Raised);
        wagesAddButton = new QPushButton(wagesFrame);
        wagesAddButton->setObjectName("wagesAddButton");
        wagesAddButton->setGeometry(QRect(30, 190, 71, 31));
        wagesAddButton->setFont(font);
        wagesAddButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #FFFFFF;\n"
"    border: 1px solid #D0D3D8;\n"
"    border-radius: 6px;\n"
"    padding: 6px 14px;\n"
"    color: #1E1E1E;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    border: 1px solid #3B82F6;\n"
"    background-color: #F0F7FF;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #E0ECFF;\n"
"}"));
        label = new QLabel(wagesFrame);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 20, 171, 41));
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(true);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    border: none;\n"
"    background: transparent;\n"
"}"));
        label->setFrameShape(QFrame::Shape::NoFrame);
        label->setFrameShadow(QFrame::Shadow::Plain);
        label_8 = new QLabel(wagesFrame);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(30, 110, 71, 31));
        wagesLine1 = new QLineEdit(wagesFrame);
        wagesLine1->setObjectName("wagesLine1");
        wagesLine1->setGeometry(QRect(100, 70, 151, 31));
        wagesLine1->setStyleSheet(QString::fromUtf8("background-color: #ECEEF1;\n"
"color: #1E1E1E;"));
        wagesLine1->setFrame(true);
        wagesLine1->setEchoMode(QLineEdit::EchoMode::Normal);
        wagesLine1->setClearButtonEnabled(false);
        wagesLine2 = new QLineEdit(wagesFrame);
        wagesLine2->setObjectName("wagesLine2");
        wagesLine2->setEnabled(true);
        wagesLine2->setGeometry(QRect(100, 110, 151, 31));
        wagesLine2->setStyleSheet(QString::fromUtf8("background-color: #ECEEF1;\n"
"color: #1E1E1E;"));
        wagesLine2->setReadOnly(false);
        label_9 = new QLabel(wagesFrame);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(30, 70, 71, 31));
        dateEdit_2 = new QDateEdit(wagesFrame);
        dateEdit_2->setObjectName("dateEdit_2");
        dateEdit_2->setGeometry(QRect(150, 290, 221, 31));
        dateEdit_2->setStyleSheet(QString::fromUtf8("background-color: #FFFFFF;\n"
"color: #1E1E1E;"));
        dateEdit_2->setCalendarPopup(true);
        dateWages = new QDateEdit(wagesFrame);
        dateWages->setObjectName("dateWages");
        dateWages->setGeometry(QRect(30, 150, 221, 31));
        dateWages->setStyleSheet(QString::fromUtf8("background-color: #FFFFFF;\n"
"color: #1E1E1E;"));
        dateWages->setDateTime(QDateTime(QDate(2025, 1, 1), QTime(0, 0, 0)));
        dateWages->setMaximumDateTime(QDateTime(QDate(9999, 12, 1), QTime(23, 59, 59)));
        dateWages->setCalendarPopup(true);
        label->raise();
        label_8->raise();
        wagesLine1->raise();
        wagesLine2->raise();
        label_9->raise();
        wagesAddButton->raise();
        dateEdit_2->raise();
        dateWages->raise();
        tabWidget->addTab(moneytab, QString());
        wagesFrame->raise();
        wagesTable->raise();
        deleteWageButton->raise();
        expenseTab = new QWidget();
        expenseTab->setObjectName("expenseTab");
        deleteExpenseButton = new QPushButton(expenseTab);
        deleteExpenseButton->setObjectName("deleteExpenseButton");
        deleteExpenseButton->setGeometry(QRect(270, 360, 121, 41));
        deleteExpenseButton->setFont(font);
        tableWidget = new QTableWidget(expenseTab);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem5);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(270, 40, 301, 311));
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
        tableWidget->setColumnCount(3);
        wagesFrame_2 = new QFrame(expenseTab);
        wagesFrame_2->setObjectName("wagesFrame_2");
        wagesFrame_2->setGeometry(QRect(10, 20, 591, 411));
        wagesFrame_2->setStyleSheet(QString::fromUtf8("background-color: #FFFFFF;\n"
"border-radius: 8px;\n"
"border: 1px solid #D0D3D8;"));
        wagesFrame_2->setFrameShape(QFrame::Shape::StyledPanel);
        wagesFrame_2->setFrameShadow(QFrame::Shadow::Raised);
        expensesAddButton_clicked = new QPushButton(wagesFrame_2);
        expensesAddButton_clicked->setObjectName("expensesAddButton_clicked");
        expensesAddButton_clicked->setGeometry(QRect(140, 230, 101, 31));
        expensesAddButton_clicked->setFont(font);
        expensesAddButton_clicked->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #FFFFFF;\n"
"    border: 1px solid #D0D3D8;\n"
"    border-radius: 6px;\n"
"    padding: 6px 14px;\n"
"    color: #1E1E1E;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    border: 1px solid #3B82F6;\n"
"    background-color: #F0F7FF;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #E0ECFF;\n"
"}"));
        lineEdit_4 = new QLineEdit(wagesFrame_2);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setEnabled(true);
        lineEdit_4->setGeometry(QRect(100, 110, 151, 31));
        lineEdit_4->setStyleSheet(QString::fromUtf8("background-color: #ECEEF1;\n"
"color: #1E1E1E;"));
        lineEdit_4->setReadOnly(false);
        label_5 = new QLabel(wagesFrame_2);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(30, 110, 71, 31));
        label_4 = new QLabel(wagesFrame_2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(30, 70, 71, 31));
        txtFirstNum_2 = new QLineEdit(wagesFrame_2);
        txtFirstNum_2->setObjectName("txtFirstNum_2");
        txtFirstNum_2->setGeometry(QRect(100, 70, 151, 31));
        txtFirstNum_2->setStyleSheet(QString::fromUtf8("background-color: #ECEEF1;\n"
"color: #1E1E1E;"));
        txtFirstNum_2->setFrame(true);
        txtFirstNum_2->setEchoMode(QLineEdit::EchoMode::Normal);
        txtFirstNum_2->setClearButtonEnabled(false);
        label_6 = new QLabel(wagesFrame_2);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(30, 20, 221, 41));
        label_6->setFont(font1);
        label_6->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    border: none;\n"
"    background: transparent;\n"
"}"));
        comboBox = new QComboBox(wagesFrame_2);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(30, 190, 221, 31));
        comboBox->setStyleSheet(QString::fromUtf8(""));
        dateEdit = new QDateEdit(wagesFrame_2);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(30, 150, 221, 31));
        dateEdit->setStyleSheet(QString::fromUtf8("background-color: #FFFFFF;\n"
"color: #1E1E1E;"));
        dateEdit->setDateTime(QDateTime(QDate(2025, 1, 2), QTime(0, 0, 0)));
        dateEdit->setCalendarPopup(true);
        tabWidget->addTab(expenseTab, QString());
        wagesFrame_2->raise();
        deleteExpenseButton->raise();
        tableWidget->raise();
        budgetTab = new QWidget();
        budgetTab->setObjectName("budgetTab");
        frame = new QFrame(budgetTab);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(19, -1, 1151, 751));
        frame->setStyleSheet(QString::fromUtf8("background-color: #FFFFFF;\n"
"border-radius: 8px;\n"
"border: 1px solid #D0D3D8;"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        chartView = new QChartView(frame);
        chartView->setObjectName("chartView");
        chartView->setGeometry(QRect(570, 20, 561, 711));
        sizePolicy.setHeightForWidth(chartView->sizePolicy().hasHeightForWidth());
        chartView->setSizePolicy(sizePolicy);
        chartView->setMaximumSize(QSize(16777215, 16777215));
        chartView->setStyleSheet(QString::fromUtf8("border-radius: 0px;\n"
"border: 0px solid #D0D3D8;"));
        tableBudget = new QTableWidget(frame);
        if (tableBudget->columnCount() < 3)
            tableBudget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableBudget->setHorizontalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableBudget->setHorizontalHeaderItem(1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableBudget->setHorizontalHeaderItem(2, __qtablewidgetitem8);
        tableBudget->setObjectName("tableBudget");
        tableBudget->setGeometry(QRect(20, 20, 521, 711));
        tableBudget->setStyleSheet(QString::fromUtf8("background-color: #ECEEF1;\n"
"color: #1E1E1E;\n"
"border-radius: 0px;\n"
"border: 0px solid #D0D3D8;"));
        tableBudget->setFrameShadow(QFrame::Shadow::Sunken);
        tabWidget->addTab(budgetTab, QString());
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        deleteWageButton->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        QTableWidgetItem *___qtablewidgetitem = wagesTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = wagesTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = wagesTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Amount", nullptr));
        deleteWageButton->setText(QCoreApplication::translate("MainWindow", "Delete Selected", nullptr));
        wagesAddButton->setText(QCoreApplication::translate("MainWindow", "ADD", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "  Monthly Pay:", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", " Amount:", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "  Name:", nullptr));
        dateWages->setDisplayFormat(QCoreApplication::translate("MainWindow", "MM/dd/yyyy", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(moneytab), QCoreApplication::translate("MainWindow", "Wages", nullptr));
        deleteExpenseButton->setText(QCoreApplication::translate("MainWindow", "Delete Selected", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Time", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Amount", nullptr));
        expensesAddButton_clicked->setText(QCoreApplication::translate("MainWindow", "ADD", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", " Amount:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "  Name:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "  Monthly Expenses:", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "  Select Item", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "  Bills", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "  Fun", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "  Groceries", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("MainWindow", "  Savings", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("MainWindow", "  Subscriptions", nullptr));

        dateEdit->setDisplayFormat(QCoreApplication::translate("MainWindow", "MM/dd/yyyy", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(expenseTab), QCoreApplication::translate("MainWindow", "Expenses", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableBudget->horizontalHeaderItem(0);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Wages", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableBudget->horizontalHeaderItem(1);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "Expenses", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableBudget->horizontalHeaderItem(2);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "Left Over", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(budgetTab), QCoreApplication::translate("MainWindow", "PieChart", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
