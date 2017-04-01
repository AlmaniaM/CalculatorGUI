/**
  * @brief Assignment 9 part B
  * @author Alexander Molodyh
  */

#ifndef CALCULATORGUI_H
#define CALCULATORGUI_H

#include <QDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QStackedLayout>
#include <QGridLayout>
#include <QString>
#include <regex>

#include "Calculator.h"

class CalculatorGUI : public QDialog
{
    Q_OBJECT

public:
    CalculatorGUI(QWidget *parent = 0);
    ~CalculatorGUI();

private:
    Calculator* calcEngine;

    double firstValue;

    QString qtString;
    QString displayString;

    //Sets up all of the buttons
    QGridLayout* getFirstLayer();

    QLineEdit* displayArea;
    QPushButton* mcButton;
    QPushButton* mrButton;
    QPushButton* msButton;
    QPushButton* mPlusButton;
    QPushButton* mMinusButton;
    QPushButton* backButton;
    QPushButton* ceButton;
    QPushButton* cButton;
    QPushButton* plusMinusButton;
    QPushButton* sqrtButton;

    QPushButton* periodButton;
    QPushButton* zeroButton;
    QPushButton* oneButton;
    QPushButton* twoButton;
    QPushButton* threeButton;
    QPushButton* fourButton;
    QPushButton* fiveButton;
    QPushButton* sixButton;
    QPushButton* sevenButton;
    QPushButton* eightButton;
    QPushButton* nineButton;

    QPushButton* plusButton;
    QPushButton* minusButton;
    QPushButton* multiplyButton;
    QPushButton* divideButton;

    QPushButton* percentButton;
    QPushButton* oneXButton;
    QPushButton* equalsButton;

public slots:
    /**
     * @brief buttonPressed Handles mathematical buttons
     */
    void buttonPressed();

    /**
     * @brief nbPressed Handles the number buttons
     */
    void nbPressed();
};

#endif // CALCULATORGUI_H
