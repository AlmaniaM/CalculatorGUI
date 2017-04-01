#include "CalculatorGUI.h"

#include <string>
#include <iostream>

using namespace std;

CalculatorGUI::CalculatorGUI(QWidget *parent):
    QDialog(parent)
{
    QVBoxLayout* mainLayout = new QVBoxLayout;

    QFont displayFont("Sans", 16, QFont::Bold, true);

    calcEngine = new Calculator;

    displayArea = new QLineEdit;
    displayArea->setMinimumHeight(50);
    displayArea->setAlignment(Qt::AlignRight);
    displayArea->setFont(displayFont);

    mainLayout->addWidget(displayArea);
    mainLayout->addLayout(getFirstLayer());

    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    setLayout(mainLayout);
}

QGridLayout* CalculatorGUI::getFirstLayer()
{
    QGridLayout* gridLayout = new QGridLayout;
    int buttonHeight = 50;
    int buttonWidth = 55;

    mcButton = new QPushButton("MC");
    mcButton->setMinimumHeight(buttonHeight);
    mcButton->setMaximumWidth(buttonWidth);
    connect(mcButton, SIGNAL(clicked()), this, SLOT());

    mrButton = new QPushButton("MR");
    mrButton->setMinimumHeight(buttonHeight);
    mrButton->setMaximumWidth(buttonWidth);
    connect(mrButton, SIGNAL(clicked()), this, SLOT());

    msButton = new QPushButton("MS");
    msButton->setMinimumHeight(buttonHeight);
    msButton->setMaximumWidth(buttonWidth);
    connect(msButton, SIGNAL(clicked()), this, SLOT());

    mPlusButton = new QPushButton("M+");
    mPlusButton->setMinimumHeight(buttonHeight);
    mPlusButton->setMaximumWidth(buttonWidth);
    connect(mPlusButton, SIGNAL(clicked()), this, SLOT());

    mMinusButton = new QPushButton("M-");
    mMinusButton->setMinimumHeight(buttonHeight);
    mMinusButton->setMaximumWidth(buttonWidth);
    connect(mMinusButton, SIGNAL(clicked()), this, SLOT());

    backButton = new QPushButton("\u21FD");
    backButton->setMinimumHeight(buttonHeight);
    backButton->setMaximumWidth(buttonWidth);
    connect(backButton, SIGNAL(clicked()), this, SLOT(buttonPressed()));

    ceButton = new QPushButton("CE");
    ceButton->setMinimumHeight(buttonHeight);
    ceButton->setMaximumWidth(buttonWidth);
    connect(ceButton, SIGNAL(clicked()), this, SLOT());

    cButton = new QPushButton("C");
    cButton->setMinimumHeight(buttonHeight);
    cButton->setMaximumWidth(buttonWidth);
    connect(cButton, SIGNAL(clicked()), this, SLOT());

    plusMinusButton = new QPushButton("\u00B1");
    plusMinusButton->setMinimumHeight(buttonHeight);
    plusMinusButton->setMaximumWidth(buttonWidth);
    connect(plusMinusButton, SIGNAL(clicked()), this, SLOT());

    sqrtButton = new QPushButton("\u221A");
    sqrtButton->setMinimumHeight(buttonHeight);
    sqrtButton->setMaximumWidth(buttonWidth);
    connect(sqrtButton, SIGNAL(clicked()), this, SLOT(buttonPressed()));

    periodButton = new QPushButton(".");
    periodButton->setMinimumHeight(buttonHeight);
    periodButton->setMaximumWidth(buttonWidth);
    connect(periodButton, SIGNAL(clicked()), this, SLOT(nbPressed()));

    zeroButton = new QPushButton("0");
    zeroButton->setMinimumHeight(buttonHeight);
    connect(zeroButton, SIGNAL(clicked()), this, SLOT(nbPressed()));

    oneButton = new QPushButton("1");
    oneButton->setMinimumHeight(buttonHeight);
    oneButton->setMaximumWidth(buttonWidth);
    connect(oneButton, SIGNAL(clicked()), this, SLOT(nbPressed()));

    twoButton = new QPushButton("2");
    twoButton->setMinimumHeight(buttonHeight);
    twoButton->setMaximumWidth(buttonWidth);
    connect(twoButton, SIGNAL(clicked()), this, SLOT(nbPressed()));

    threeButton = new QPushButton("3");
    threeButton->setMinimumHeight(buttonHeight);
    threeButton->setMaximumWidth(buttonWidth);
    connect(threeButton, SIGNAL(clicked()), this, SLOT(nbPressed()));

    fourButton = new QPushButton("4");
    fourButton->setMinimumHeight(buttonHeight);
    fourButton->setMaximumWidth(buttonWidth);
    connect(fourButton, SIGNAL(clicked()), this, SLOT(nbPressed()));

    fiveButton = new QPushButton("5");
    fiveButton->setMinimumHeight(buttonHeight);
    fiveButton->setMaximumWidth(buttonWidth);
    connect(fiveButton, SIGNAL(clicked()), this, SLOT(nbPressed()));

    sixButton = new QPushButton("6");
    sixButton->setMinimumHeight(buttonHeight);
    sixButton->setMaximumWidth(buttonWidth);
    connect(sixButton, SIGNAL(clicked()), this, SLOT(nbPressed()));

    sevenButton = new QPushButton("7");
    sevenButton->setMinimumHeight(buttonHeight);
    sevenButton->setMaximumWidth(buttonWidth);
    connect(sevenButton, SIGNAL(clicked()), this, SLOT(nbPressed()));

    eightButton = new QPushButton("8");
    eightButton->setMinimumHeight(buttonHeight);
    eightButton->setMaximumWidth(buttonWidth);
    connect(eightButton, SIGNAL(clicked()), this, SLOT(nbPressed()));

    nineButton = new QPushButton("9");
    nineButton->setMinimumHeight(buttonHeight);
    nineButton->setMaximumWidth(buttonWidth);
    connect(nineButton, SIGNAL(clicked()), this, SLOT(nbPressed()));

    multiplyButton = new QPushButton("*");
    multiplyButton->setMinimumHeight(buttonHeight);
    multiplyButton->setMaximumWidth(buttonWidth);
    connect(multiplyButton, SIGNAL(clicked()), this, SLOT(buttonPressed()));

    divideButton = new QPushButton("/");
    divideButton->setMinimumHeight(buttonHeight);
    divideButton->setMaximumWidth(buttonWidth);
    connect(divideButton, SIGNAL(clicked()), this, SLOT(buttonPressed()));

    percentButton = new QPushButton("%");
    percentButton->setMinimumHeight(buttonHeight);
    percentButton->setMaximumWidth(buttonWidth);
    connect(percentButton, SIGNAL(clicked()), this, SLOT());

    oneXButton = new QPushButton("1/x");
    oneXButton->setMinimumHeight(buttonHeight);
    oneXButton->setMaximumWidth(buttonWidth);
    connect(oneXButton, SIGNAL(clicked()), this, SLOT());

    equalsButton = new QPushButton("=");
    equalsButton->setMaximumHeight(110);
    equalsButton->setMaximumWidth(buttonWidth);
    connect(equalsButton, SIGNAL(clicked()), this, SLOT(buttonPressed()));

    plusButton = new QPushButton("+");
    plusButton->setMinimumHeight(buttonHeight);
    plusButton->setMaximumWidth(buttonWidth);
    connect(plusButton, SIGNAL(clicked()), this, SLOT(buttonPressed()));

    minusButton = new QPushButton("-");
    minusButton->setMinimumHeight(buttonHeight);
    minusButton->setMaximumWidth(buttonWidth);
    connect(minusButton, SIGNAL(clicked()), this, SLOT(buttonPressed()));


    gridLayout->addWidget(mcButton, 0, 0);
    gridLayout->addWidget(mrButton, 0, 1);
    gridLayout->addWidget(msButton, 0, 2);
    gridLayout->addWidget(mPlusButton, 0, 3);
    gridLayout->addWidget(mMinusButton, 0, 4);

    gridLayout->addWidget(backButton, 1, 0);
    gridLayout->addWidget(ceButton, 1, 1);
    gridLayout->addWidget(cButton, 1, 2);
    gridLayout->addWidget(plusMinusButton, 1, 3);
    gridLayout->addWidget(sqrtButton, 1, 4);

    gridLayout->addWidget(sevenButton, 2, 0);
    gridLayout->addWidget(eightButton, 2, 1);
    gridLayout->addWidget(nineButton, 2, 2);
    gridLayout->addWidget(divideButton, 2, 3);
    gridLayout->addWidget(percentButton, 2, 4);

    gridLayout->addWidget(fourButton, 3, 0);
    gridLayout->addWidget(fiveButton, 3, 1);
    gridLayout->addWidget(sixButton, 3, 2);
    gridLayout->addWidget(multiplyButton, 3, 3);
    gridLayout->addWidget(oneXButton, 3, 4);

    gridLayout->addWidget(oneButton, 4, 0);
    gridLayout->addWidget(twoButton, 4, 1);
    gridLayout->addWidget(threeButton, 4, 2);
    gridLayout->addWidget(minusButton, 4, 3);
    gridLayout->addWidget(equalsButton, 4, 4, 2, 1);
    equalsButton->setMinimumHeight(50);

    gridLayout->addWidget(zeroButton, 5, 0, 1, 2);
    gridLayout->addWidget(periodButton, 5, 2);
    gridLayout->addWidget(plusButton, 5, 3);

    return gridLayout;
}

void CalculatorGUI::buttonPressed()
{
    QObject* sender = QObject::sender();
    QPushButton* pressedButton = dynamic_cast<QPushButton*>(sender);

    displayString += pressedButton->text();
    displayArea->setText(displayString);

    if(plusButton == pressedButton)
    {
        qtString.clear();
        calcEngine->store(firstValue);
        calcEngine->handleOperation(calcEngine->ADD);
    }
    else if(minusButton == pressedButton)
    {
        qtString.clear();
        calcEngine->store(firstValue);
        calcEngine->handleOperation(calcEngine->SUBTRACT);
    }
    else if(multiplyButton == pressedButton)
    {
        qtString.clear();
        calcEngine->store(firstValue);
        calcEngine->handleOperation(calcEngine->MULTIPLY);
    }
    else if(divideButton == pressedButton)
    {
        qtString.clear();
        calcEngine->store(firstValue);
        calcEngine->handleOperation(calcEngine->DIVIDE);
    }
    else if(sqrtButton == pressedButton)
    {
        qtString.clear();
        calcEngine->store(firstValue);
        calcEngine->handleOperation(calcEngine->SQRT);
    }
    else if(equalsButton == pressedButton)
    {
        qtString.clear();
        calcEngine->store(firstValue);
        displayString.clear();
        QString temp = QString::number(calcEngine->equalsPressed());
        displayArea->setText(temp);

    }
    else if(backButton == pressedButton)
    {
        qtString.clear();
        calcEngine->clear();
        displayString.clear();
        displayArea->setText(displayString);
    }
}

void CalculatorGUI::nbPressed()
{
    QObject* sender = QObject::sender();
    QPushButton* pressedButton = dynamic_cast<QPushButton*>(sender);

    displayString += pressedButton->text();
    displayArea->setText(displayString);

    qtString += pressedButton->text();
    bool ok;
    firstValue = qtString.toDouble(&ok);
}

CalculatorGUI::~CalculatorGUI()
{

}






























