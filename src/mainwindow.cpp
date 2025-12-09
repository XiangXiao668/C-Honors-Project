#include "../include/mainwindow.h"
#include "./ui_mainwindow.h"

//includes for the Pie Chart
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChart>
#include <QtCharts/QPieSlice>

//includes are for the resize animations
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

    //need to change everything from foo bar call to connect()
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

//change from foo bar to connection
//wages button adds text from QStrings and date from QDate to the wages table/
void MainWindow::on_wagesAddButton_clicked()
{
    QString text1 = ui->wagesLine1->text();
    QString text2 = ui->wagesLine2->text();
    QDate dateEditDate = ui->dateWages->date();

    //convert amount string to double
    double amount = text2.toDouble();


    Income income;
    income.name = text1;
    income.amount = amount;
    income.date = dateEditDate;

    member_budget.addIncome(income); //member_budget instantiated in the .h

    int row = ui->wagesTable->rowCount();
    ui->wagesTable->insertRow(row);

    ui->wagesTable->setItem(row, 0, new QTableWidgetItem(text1));
    ui->wagesTable->setItem(row, 1, new QTableWidgetItem(text2));
    ui->wagesTable->setItem(row, 2, new QTableWidgetItem(dateEditDate.toString("yyyy-MM-dd")));


    //Update the last-page wages summary table
    appendIncomeToSummary(amount);

    //clear inputs after adding
    ui->wagesLine1->clear();
    ui->wagesLine2->clear();
}

//change from foo bar to connection
void MainWindow::on_expensesAddButton_clicked()
{
    QString text1   = ui->expenseName->text();        // expense name
    QString text2   = ui->expenseAmount->text();      // amount as string
    QString category = ui->categoryExpense->currentText();
    QDate dateEditDate = ui->dateExpense->date();

    //convert amount to double
    double amount = text2.toDouble();

    Expense expense;
    expense.name     = text1;
    expense.amount   = amount;
    expense.category = category;
    expense.date     = dateEditDate;

    member_budget.addExpense(expense); //member_budget instantiated in the .h

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
    int row = ui->wagesTable->currentRow();
    if (row < 0)
        return;

    //remove row from vector
    member_budget.removeIncomeAt(row); //member_budget instantiated in the .h

    //remove row from wages table
    ui->wagesTable->removeRow(row);

    //Rebuild the wages column in the final table
    refreshSummaryWagesColumn();
}

//wage delete selected button code
void MainWindow::on_deleteExpenseButton_clicked()
{
    int row = ui->expenseTable->currentRow();


    if (row < 0)
        return;

    // Remove row
    ui->expenseTable->removeRow(row);
}

// Animates window size when the current tab changes
void MainWindow::onTabChanged(int index)
{
    QSize targetSize;

    switch (index) {
        case 2: // Pie tab
            targetSize = QSize(1200, 800);
            break;
        case 1: // Expense tab
            targetSize = QSize(730, 500);
            break;
        default: // Income tab
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

void MainWindow::appendIncomeToSummary(double amount)
{
    QTableWidget *table = ui->tableBudget;

    // Make sure it has at least 3 columns: Wages, Expenses, Total Left Over
    if (table->columnCount() < 3) {
        table->setColumnCount(3);
        QStringList headers;
        headers << "Wages" << "Expenses" << "Total Left Over";
        table->setHorizontalHeaderLabels(headers);
    }

    // New row at the bottom
    int row = table->rowCount();
    table->insertRow(row);

    // Put the income amount in the Wages column (col 0), same column every time
    auto *wagesItem = new QTableWidgetItem(QString::number(amount, 'f', 2));
    table->setItem(row, 0, wagesItem);

}

void MainWindow::refreshSummaryWagesColumn()
{
    QTableWidget *table = ui->tableBudget;
    const auto &incomes = member_budget.getIncomes();

    // Make sure we have at least as many rows as incomes
    if (table->rowCount() < incomes.size()) {
        table->setRowCount(incomes.size());
    }

    int rowCount = table->rowCount();

    // For each row:
    // - if there's an income at that index, show its amount in col 0
    // - otherwise clear the wages cell (but leave other columns alone)
    for (int row = 0; row < rowCount; ++row) {

        QTableWidgetItem *item = table->item(row, 0);
        if (!item) {
            item = new QTableWidgetItem();
            table->setItem(row, 0, item);
        }

        if (row < incomes.size()) {
            // There *is* an income for this row index
            item->setText(QString::number(incomes[row].amount, 'f', 2));
        } else {
            // No income for this row index anymore → clear wages only
            item->setText("");
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
