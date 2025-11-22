#include "../include/mainwindow.h"
#include "./ui_mainwindow.h"

//includes for the Pie Chart
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChart>
#include <QtCharts/QPieSlice>

//includes are for the resize animation
#include <QPainter>
#include <QTabWidget>
#include <QPropertyAnimation>
#include <QEasingCurve>

// allows for table header resize
#include <QHeaderView>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    //makes this ui the mainwindow.ui
    ui->setupUi(this);

    ////////////////// Window setup ///////////////////////////
    resize(625, 500);  //sets initial window size
    setWindowTitle("Honor's Budget App"); //Set window title
    setWindowFlags(windowFlags() & ~Qt::WindowMaximizeButtonHint); //Remove the maximize button

    ////////////////// Initial UI State ///////////////////////////

    //sets tab page to the first tab
    ui->tabWidget->setCurrentIndex(0);

    //wagesTable text not editable
    ui->wagesTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //resizes the tableBudgets columns to fit
    ui->tableBudget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ////////////////// Connections ///////////////////////////

    //this connects signal of the tab index to onTabChanged to create a tab animation.
    connect(ui->tabWidget, &QTabWidget::currentChanged,
            this, &MainWindow::onTabChanged);


    ////////////////// Pie Chart setup ///////////////////////////
    auto *series = new QPieSeries(this);
    series->append("Rent",       1200);
    series->append("Groceries",   400);
    series->append("Utilities",   150);
    series->append("Fun",         200);
    series->append("Savings",     300);

    // add the pie chart
    auto *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Monthly Budget Breakdown");
    chart->legend()->setAlignment(Qt::AlignRight);

    // chartView = the promoted widget in the .ui file
    ui->chartView->setChart(chart);
    ui->chartView->setRenderHint(QPainter::Antialiasing);

}

//wages button adds text from QStrings and date from QDate to the wages table/
void MainWindow::on_wagesAddButton_clicked()
{

    QString text1 = ui->wagesLine1->text();
    QString text2 = ui->wagesLine2->text();
    QDate dateEditDate = ui->dateWages->date();

    int row = ui->wagesTable->rowCount();
    ui->wagesTable->insertRow(row);

    ui->wagesTable->setItem(row, 0, new QTableWidgetItem(text1));
    ui->wagesTable->setItem(row, 1, new QTableWidgetItem(text2));
    ui->wagesTable->setItem(row, 2, new QTableWidgetItem(dateEditDate.toString("yyyy-MM-dd")));

    // clear inputs after adding
    ui->wagesLine1->clear();
    ui->wagesLine2->clear();
}

void MainWindow::on_expensesAddButton_clicked()
{

    QString text1 = ui->expenseName->text();
    QString text2 = ui->expenseAmount->text();
    QString category = ui->categoryExpense->currentText();
    QDate dateEditDate = ui->dateExpense->date();

    int row = ui->expenseTable->rowCount();
    ui->expenseTable->insertRow(row);

    ui->expenseTable->setItem(row, 0, new QTableWidgetItem(text1));
    ui->expenseTable->setItem(row, 1, new QTableWidgetItem(text2));
    ui->expenseTable->setItem(row, 2, new QTableWidgetItem(category));
    ui->expenseTable->setItem(row, 3, new QTableWidgetItem(dateEditDate.toString("yyyy-MM-dd")));

    //clear text from expense text line
    ui->expenseName->clear();
    ui->expenseAmount->clear();

}

//wage delete selected button code
void MainWindow::on_deleteWageButton_clicked()
{
    // Which row is currently selected?
    int row = ui->wagesTable->currentRow();

    // If nothing is selected, do nothing
    if (row < 0)
        return;

    // Remove row
    ui->wagesTable->removeRow(row);
}

//wage delete selected button code
void MainWindow::on_deleteExpenseButton_clicked()
{
    // Which row is currently selected?
    int row = ui->expenseTable->currentRow();

    // If nothing is selected, do nothing
    if (row < 0)
        return;

    // Remove that row
    ui->expenseTable->removeRow(row);
}

// Animates window size when the current tab changes
void MainWindow::onTabChanged(int index)
{
    QSize targetSize;

    switch (index) {
        case 2: // Charts tab
            targetSize = QSize(1200, 800);
            break;
        case 1: // Budget tables tab
            targetSize = QSize(730, 500);
            break;
        default: // Home / other tabs
            targetSize = QSize(625, 500);
            break;
    }

    auto *anim = new QPropertyAnimation(this, "size");
    anim->setDuration(300);
    anim->setStartValue(size());
    anim->setEndValue(targetSize);
    anim->setEasingCurve(QEasingCurve::InOutCubic);
    anim->start(QAbstractAnimation::DeleteWhenStopped);
}

MainWindow::~MainWindow()
{
    delete ui;
}
