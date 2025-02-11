#include "lcd.h"

Lcd::Lcd() {}

double Lcd::getNumber()
{
    return value.toDouble();
}

QString Lcd::getValue()
{
    return value;
}

void Lcd::addNumber(int num)
{
    if (value.size() < LCD_MAX_SIZE) {
        value += QString::number(num);
    }
}

void Lcd::addDot()
{
    if (!value.contains(".")) {
        value += ".";
    }
}

void Lcd::clear()
{
    value = "";
}

void Lcd::setNumber(double num)
{
    value = QString::number(num);
}
