#ifndef CALCHISTORY_H
#define CALCHISTORY_H

#include <QDialog>

namespace Ui {
class CalcHistory;
}

class CalcHistory : public QDialog
{
    Q_OBJECT

public:
    explicit CalcHistory(QWidget *parent = 0);
    ~CalcHistory();

public slots:
    void AddNewEntry(char*,QString&);

private:
    Ui::CalcHistory *ui;
};

#endif // CALCHISTORY_H
