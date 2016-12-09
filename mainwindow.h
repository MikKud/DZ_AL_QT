#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "server.h"
#include "Factor.h"
#include "binom.h"
#include "calchistory.h"
#include <QMessageBox>
#include <sstream>

extern unsigned long int  MAX_INT;

using namespace  std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void set_port(unsigned short);
    void set_new_col_client(int);
    void rezultwelldone();
    void set_proc(float);
    void on_pushButton_2_clicked();

signals:
    void GetNewResult(char*,QString&);

private:
    Server s;
    CalcHistory* hist;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
