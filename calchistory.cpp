#include "calchistory.h"
#include "ui_calchistory.h"

CalcHistory::CalcHistory(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CalcHistory)
{
    ui->setupUi(this);
}

CalcHistory::~CalcHistory()
{
    delete ui;
}

void CalcHistory::AddNewEntry(QString& expr) {
    ui->listWidget->addItem(expr);
}
