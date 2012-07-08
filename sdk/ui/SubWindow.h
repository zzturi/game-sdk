#pragma once

#include "ui/Widget.h"

namespace sdk {

class SubWindow : public Widget
{
    Widget * m_selectedWidget;

public:
    SubWindow(Widget * parent,
              float x,
              float y,
              float width,
              float height);
    SubWindow(Widget * parent = 0);
    ~SubWindow();
    void selectPreviousWidget();
    void selectNextWidget();

protected:
    virtual void inputEvent(const CL_InputEvent & event, const CL_InputState &);
};

}
