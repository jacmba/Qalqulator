#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QList>
#include <QMap>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    resulted = false;

    ui->setupUi(this);

    setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint);
    setFixedSize(this->size());

    connect(ui->exitButton, SIGNAL(clicked()), SLOT(onExitClick()));

    QList<QPushButton*> numberButtons = {
        ui->button0,
        ui->button1,
        ui->button2,
        ui->button3,
        ui->button4,
        ui->button5,
        ui->button6,
        ui->button7,
        ui->button8,
        ui->button9
    };

    for (int i = 0; i < numberButtons.size(); i++) {
        connect(numberButtons[i], &QPushButton::clicked, this, [=]() {
            if (resulted) {
                lcd.clear();
                resulted = false;
            }

            lcd.addNumber(i);
            updateLcd();
        });
    }

    connect(ui->buttonDot, SIGNAL(clicked()), SLOT(onDotClick()));

    opMap = {
        {ADD, ui->buttonAdd},
        {SUBTRACT, ui->buttonSubtract},
        {MULTIPLY, ui->buttonMultiply},
        {DIVIDE, ui->buttonDivide}
    };

    for (auto it = opMap.constBegin(); it != opMap.constEnd(); ++it) {
        connect(it.value(), &QPushButton::clicked, this, [=]() {
            calculator.setOperation(it.key(), lcd.getNumber());
            lcd.clear();
            updateLcd();
        });
    }

    connect(ui->buttonCalc, SIGNAL(clicked()), SLOT(onCalculateClick()));

    connect(ui->clearButton, SIGNAL(clicked()), SLOT(onClearClick()));

    connect(ui->action_About, SIGNAL(triggered()), SLOT(onAboutClick()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateLcd()
{
    ui->lcdLabel->setText(lcd.getValue());
}

void MainWindow::onExitClick()
{
    close();
}

void MainWindow::onDotClick()
{
    if(resulted) {
        lcd.clear();
        resulted = false;
    }
    lcd.addDot();
    updateLcd();
}

void MainWindow::onCalculateClick()
{
    if (resulted) {
        return;
    }

    double result = calculator.calculate(lcd.getNumber());
    lcd.setNumber(result);
    updateLcd();
    resulted = true;
}

void MainWindow::onClearClick()
{
    lcd.clear();
    updateLcd();
}

void MainWindow::onAboutClick()
{
    QString content = "Qalqulator v1.0.0\n";
    content += "\n";
    content += "Copyleft Jacinto Mba 2025";

    QMessageBox::about(this, "About Qalqulator", content);
}
