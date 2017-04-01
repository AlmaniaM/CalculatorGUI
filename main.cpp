#include <iostream>

#include <QApplication>

#include "CalculatorGUI.h"

using namespace std;

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    CalculatorGUI cG;
    cG.show();

    return app.exec();
}

