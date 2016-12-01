#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <boost/scope_exit.hpp>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    hist = new CalcHistory;
    connect(s.get_acc(),SIGNAL(rezultready()),this,SLOT(rezultwelldone()));
    connect(s.get_acc(),SIGNAL(col_clientchanged(int)),this,SLOT(set_new_col_client(int)));
    connect(s.get_acc(),SIGNAL(PortOK(unsigned short)),this,SLOT(set_port(unsigned short)));
    connect(s.get_acc(), SIGNAL(UpdateProcInWin(float)), this, SLOT(set_proc(float)));
    connect(this, SIGNAL(GetNewResult(QString&)), hist, SLOT(AddNewEntry(QString&)));
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    if (s.switchOn)
        s.Stop();
    delete hist;
    delete ui;
}

void MainWindow::set_port(unsigned short port){
    QString temp= QString::fromStdString(to_string(port));
    ui->lineEdit_2->setText(temp);
}

void MainWindow::set_new_col_client(int col){
    QString temp= QString::fromStdString(to_string(col));
    ui->lineEdit_3->setText(temp);
}

void MainWindow::rezultwelldone(){
    if (ui->lineEdit_5->text().toStdString() ==""){
        mpz_class rez;
        char* r = new char(MAX_INT);
        mpz_init(rez.get_mpz_t());
        rez=1;
        for (int i=0;i<rezult.size();i++){
            rez=rez*rezult[i];
        }
        mpz_get_str(r,10,rez.get_mpz_t());
        ui->lineEdit_5->setText(r);
        QPalette *palette = new QPalette();
        palette->setColor(QPalette::Base,Qt::green);
        ui->lineEdit_5->setPalette(*palette);
        string Number = ui->lineEdit->text().toStdString();
        string Result(r);
        if(ui->radioButton->isChecked())
            Number = Number + "! = " + Result;
        if(ui->radioButton_2->isChecked())
            Number = "(" + Number + ") = " + Result;
        QString temp = QString::fromStdString(Number);
        emit GetNewResult(temp);
        delete r;
        delete palette;
    }
}

void MainWindow::on_pushButton_clicked()
{ 
    control.clear();
    rezult.clear();
    try{
        if (!(ui->radioButton->isChecked()||ui->radioButton_2->isChecked()))
            throw "Не выбрана операция.";
        QPalette *palette = new QPalette();
        palette->setColor(QPalette::Base,Qt::white);
        ui->lineEdit_5->setPalette(*palette);
        ui->lineEdit_5->clear();
        mpz_class N, K;
        mpz_init(N.get_mpz_t());
        mpz_init(K.get_mpz_t());
        string str=ui->lineEdit->text().toStdString();
        BOOST_SCOPE_EXIT((palette)){
            delete palette;
       } BOOST_SCOPE_EXIT_END
        if (ui->radioButton->isChecked()) {
            if (str==""){
                throw "Неверный формат ввода, введитe числo в формате число1";
            }
            if (str=="0"){
                ui->lineEdit_5->setText("1");
                QPalette *palette = new QPalette();
                palette->setColor(QPalette::Base,Qt::green);
                ui->lineEdit_5->setPalette(*palette);
                ui->lineEdit_4->setText("100.000");
                string Number = ui->lineEdit->text().toStdString();
                Number = Number + "! = " + "1";
                QString temp = QString::fromStdString(Number);
                emit GetNewResult(temp);
                return;
            }
                mpz_set_str(N.get_mpz_t(),str.c_str(),10);
                Factor(N);
        }

        if (ui->radioButton_2->isChecked()) {
        std::istringstream iss(str, std::istringstream::in);
        string n, k;
        iss >> n; iss >> k;
        if (n=="" || k==""){
            throw "Неверный формат ввода, введите два числа в формате число1_число2";
        }
        mpz_set_str(N.get_mpz_t(),n.c_str(),10);
        mpz_set_str(K.get_mpz_t(),k.c_str(),10);
        if (N < K){
            ui->lineEdit_5->setText("0");
            QPalette *palette = new QPalette();
            palette->setColor(QPalette::Base,Qt::green);
            ui->lineEdit_5->setPalette(*palette);
            ui->lineEdit_4->setText("100.000");
            string Number = ui->lineEdit->text().toStdString();
            Number = "(" + Number + ") = " + "0";
            QString temp = QString::fromStdString(Number);
            emit GetNewResult(temp);
            return;
        }
        Binom(N, K);
    }
    for (int i =0; i<tasks[0].size();++i){
    rezult.push_back(0);
    control.push_back(0);
    }

    if (!s.switchOn){
    s.Start();
    s.switchOn = true;
    }
    set_proc(0);
    }
   catch(char const* message){
       QMessageBox::warning(this,"Warning", message);
   }
}

void MainWindow::set_proc(float proc){
    QString temp= QString::fromStdString(to_string(proc));
    ui->lineEdit_4->setText(temp);
}



void MainWindow::on_pushButton_2_clicked()
{
    hist->show();
}
