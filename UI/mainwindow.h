#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>
#include <QPushButton>
#include "lcd.h"
#include "calculator.h"

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

private:
    Ui::MainWindow *ui;

    Lcd lcd;
    Calculator calculator;
    bool resulted;
    QMap<OperationType, QPushButton*> opMap;

    void updateLcd();

private slots:
    void onExitClick();
    void onDotClick();
    void onCalculateClick();
    void onClearClick();
    void onAboutClick();
    void onSquareClick();
    void onSqrtClick();
};
#endif // MAINWINDOW_H
