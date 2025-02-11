#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFontDatabase>
#include <QList>
#include <QMap>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // Setup UI
    resulted = false;

    ui->setupUi(this);

    setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint);
    setFixedSize(this->size());

    // Set LCD font
    int geekFont = QFontDatabase::addApplicationFont(":/fonts/Open 24 Display St.ttf");
    QString geekFamily = QFontDatabase::applicationFontFamilies(geekFont).at(0);
    ui->lcdLabel->setFont(QFont(geekFamily));

    // Connect actions

    connect(ui->exitButton, SIGNAL(clicked()), SLOT(onExitClick()));

    // Numbers actions mapping
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

    // Disable mouse events for button labels
    ui->powerLabel->setAttribute(Qt::WA_TransparentForMouseEvents);

    // Binary operations connection mapping
    opMap = {
        {ADD, ui->buttonAdd},
        {SUBTRACT, ui->buttonSubtract},
        {MULTIPLY, ui->buttonMultiply},
        {DIVIDE, ui->buttonDivide},
        {POWER, ui->buttonPower}
    };

    for (auto it = opMap.constBegin(); it != opMap.constEnd(); ++it) {
        connect(it.value(), &QPushButton::clicked, this, [=]() {
            calculator.setOperation(it.key(), lcd.getNumber());
            lcd.clear();
            updateLcd();
        });
    }

    // Unary operations button connections
    connect(ui->buttonSquare, SIGNAL(clicked()), SLOT(onSquareClick()));
    connect(ui->buttonSqrt, SIGNAL(clicked()), SLOT(onSqrtClick()));

    // Action buttons connections
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

    QMessageBox::about(nullptr, "About Qalqulator", content);
}

void MainWindow::onSquareClick()
{
    double result = calculator.calculateSquare(lcd.getNumber());
    lcd.setNumber(result);
    updateLcd();
}

void MainWindow::onSqrtClick()
{
    double result = calculator.calculateSqrt(lcd.getNumber());
    lcd.setNumber(result);
    updateLcd();
}
