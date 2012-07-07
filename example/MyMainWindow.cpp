#include "MyMainWindow.h"
#include <iostream>

using namespace std;

MyMainWindow::MyMainWindow()
    : MainWindow()
{
}

MyMainWindow::~MyMainWindow()
{
}

void MyMainWindow::setup()
{
    button1 = new Button(this, 50.f, 100.f, 100.0f, 40.f);
    button1->onDoubleClick.connect(this, &MyMainWindow::on_Button1_doubleClick);
    addWidget(button1);

    button2 = new Button(this, 50.f, 150.f, 100.0f, 40.f);
    button2->onDoubleClick.connect(this, &MyMainWindow::on_Button2_doubleClick);
    addWidget(button2);

    button3 = new Button(this, 50.f, 200.f, 100.0f, 40.f);
    addWidget(button3);
    button3->setState(RollOver);

    button4 = new Button(this, 50.f, 250.f, 100.0f, 40.f);
    addWidget(button4);
}

void MyMainWindow::on_Button1_doubleClick()
{
    cout << "onDoubleClick (button1)" << endl;
}

void MyMainWindow::on_Button2_doubleClick()
{
    cout << "onDoubleClick (button2)" << endl;
}
