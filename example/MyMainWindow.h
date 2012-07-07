#pragma once

#include "ui/MainWindow.h"
#include "ui/Button.h"
#include "misc/sigslot.h"

using namespace sdk;

class MyMainWindow : public MainWindow, public sigslot::has_slots<>
{
    Button * button1;
    Button * button2;
    Button * button3;
    Button * button4;

public:
    MyMainWindow();
    ~MyMainWindow();
    virtual void setup();
    void on_Button1_doubleClick();
    void on_Button2_doubleClick();
};
