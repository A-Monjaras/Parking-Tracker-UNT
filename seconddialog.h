// seconddialog.h

#ifndef SECONDDIALOG_H
#define SECONDDIALOG_H

#include <QDialog>
#include <QTableWidget>
#include <QPushButton>
#include <QVBoxLayout>

class SecondDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SecondDialog(QWidget *parent = nullptr);
    ~SecondDialog();

private:
    void createLayout();

    QTableWidget *tableWidget;
    QVBoxLayout *mainLayout;

private slots:
    void onGetDirectionsButtonClicked(int row);
};

#endif // SECONDDIALOG_H
