#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void convertUnits();

private:
    Ui::MainWindow *ui;
    // UI Elements
    QComboBox *cmbUnitTo;
    QComboBox *cmbUnitFrom;
    QLabel *lblOutputResult;
    QLabel *lblFrom;
    QLabel *lblTo;
    QLabel *lblHeader;
    QLineEdit *lnEdtInput;
    QPushButton *btnSubmit;

    QString fromUnit;
    QString toUnit;
};

#endif // MAINWINDOW_H
