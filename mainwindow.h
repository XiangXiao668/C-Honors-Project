#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onTabChanged(int index);   // called when the current tab changes
    void on_wagesAddButton_clicked();
    void on_deleteWageButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
