#include "mainwindow.h"
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

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    //makes this ui the mainwindow.ui
    ui->setupUi(this);

    //sets the ui's tab page to the first page of the tab
    ui->tabWidget->setCurrentIndex(0);

    //this connection connects the tab index to onTabChanged to create a tab animation.
    connect(ui->tabWidget, &QTabWidget::currentChanged,
            this, &MainWindow::onTabChanged);

    //resizes the tableBudgets columns to fit
     ui->tableBudget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    resize(625, 500);  //sets initial window size

    //Set window title
    setWindowTitle("Honor's Budget App");

    //Remove the maximize button:
    setWindowFlags(windowFlags() & ~Qt::WindowMaximizeButtonHint);

    // Create the data for the pie chart !!will need to add changeing veriables here!!
    auto *series = new QPieSeries(this);
    series->append("Rent",       1200);
    series->append("Groceries",   400);
    series->append("Utilities",   150);
    series->append("Fun",         200);
    series->append("Savings",     300);

    // Optional: explode one slice / show labels
    //QPieSlice *highlight = series->slices().at(0);
   // highlight->setExploded(true);
    //highlight->setLabelVisible(true);

    // Create the chart
    auto *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Monthly Budget Breakdown");
    chart->legend()->setAlignment(Qt::AlignRight);

    // chartView = the promoted widget in your .ui file
    ui->chartView->setChart(chart);
    ui->chartView->setRenderHint(QPainter::Antialiasing);


}

//wages button code
void MainWindow::on_wagesAddButton_clicked()
{
    qDebug() << "BUTTON CLICKED";
    QString text1 = ui->wagesLine1->text();
    QString text2 = ui->wagesLine2->text();
    //QDate calendarDate = ui->dateWages->selectedDate();
    QDate dateEditDate = ui->dateWages->date();

    int row = ui->wagesTable->rowCount();
    ui->wagesTable->insertRow(row);

    ui->wagesTable->setItem(row, 0, new QTableWidgetItem(text1));
    ui->wagesTable->setItem(row, 1, new QTableWidgetItem(text2));
    //ui->tableWidget->setItem(row, 2, new QTableWidgetItem(calendarDate.toString("yyyy-MM-dd")));
    ui->wagesTable->setItem(row, 2, new QTableWidgetItem(dateEditDate.toString("yyyy-MM-dd")));
}

void MainWindow::on_deleteWageButton_clicked()
{
    // Which row is currently selected?
    int row = ui->wagesTable->currentRow();

    // If nothing is selected, do nothing
    if (row < 0)
        return;

    // Remove that row
    ui->wagesTable->removeRow(row);
}

//Changes tab 3 size and animation for the Tables and Pie Chart
void MainWindow::onTabChanged(int index)
{
    // Choose target size based on tab
    // Example: index 1 (second tab) = budgeting tab → bigger
    QSize targetSize;

    if (index == 2) {
        targetSize = QSize(1200, 800);   // expanded size
    } else {
        targetSize = QSize(625, 500);    // compact size
    }

    // Animate the window resize
    auto *anim = new QPropertyAnimation(this, "size");
    anim->setDuration(300);                          // 300 ms animation
    anim->setStartValue(size());                     // current window size
    anim->setEndValue(targetSize);                   // target size
    anim->setEasingCurve(QEasingCurve::InOutCubic);  // smooth easing
    anim->start(QAbstractAnimation::DeleteWhenStopped);
}

MainWindow::~MainWindow()
{
    delete ui;
}
