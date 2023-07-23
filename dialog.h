#ifndef DIALOG_H
#define DIALOG_H
#include "userdatabase.h"

#include <QDialog>


QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    Dialog();
    ~Dialog();
    void ChangeText();

private slots:



private:
    Ui::Dialog *ui;

};
#endif // DIALOG_H
