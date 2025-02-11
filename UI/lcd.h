#ifndef LCD_H
#define LCD_H

#include <QString>

#define LCD_MAX_SIZE 15

class Lcd
{
public:
    Lcd();

    double getNumber();
    QString getValue();
    void addNumber(int num);
    void addDot();
    void clear();
    void setNumber(double num);

private:
    QString value;
};

#endif // LCD_H
