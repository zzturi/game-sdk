#include "SubWindow.h"
#include "misc/Common.h"

#include <iostream>
using namespace std;

namespace sdk {

SubWindow::SubWindow(Widget * parent,
                     float x,
                     float y,
                     float width,
                     float height)
    : Widget(parent, x, y, width, height)
{
    enableInputEvents();
}

SubWindow::SubWindow(Widget * parent)
    : Widget(parent)
{
    setSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    enableInputEvents();
}

SubWindow::~SubWindow()
{
}

void SubWindow::inputEvent(const CL_InputEvent & event, const CL_InputState &)
{
    cout << "SubWindow::inputEvent" << endl;
    switch (event.type) {
    case CL_InputEvent::axis_moved:
        //if (m_state != RollOver || !m_selectable)
        //    break;
        switch (event.id) {
        case 0:  // horizontal move
            if (event.axis_pos < 0) {
                cout << "left" << endl;
                selectPreviousWidget();
            } else if (event.axis_pos > 0) {
                cout << "right" << endl;
                selectNextWidget();
            }
            break;
        case 1:  // vertical move
            if (event.axis_pos < 0) {
                cout << "up" << endl;
                selectPreviousWidget();
            } else if (event.axis_pos > 0) {
                cout << "down" << endl;
                selectNextWidget();
            }
            break;
        default:
            break;
        }
    default:
        break;
    }
}

void SubWindow::selectPreviousWidget()
{
}

void SubWindow::selectNextWidget()
{
}

}
