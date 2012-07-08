#pragma once

#include <vector>
#include "../graphics/geometry.h"
#include "../graphics/Sprite.h"
#include "../misc/String.h"

#include <ClanLib/Display/Window/input_event.h>
#include <ClanLib/Display/Window/input_state.h>
#include <ClanLib/Core/Signals/slot.h>
#include "../misc/sigslot.h"

namespace sdk {

class Widget : public Rect
{
    Widget * m_parent;

    std::vector<Widget *> m_children;

    enum LayoutType {
        Float,
        Horizontal,
        Vertical
    } m_layout;

    float m_hspacing;
    float m_vspacing;

    bool m_autoResize;

    bool m_visible;
    int m_alpha;

    Sprite * m_mouseCursor;

    Rect m_viewPort;

    bool m_selectable;

    String m_title;

    CL_Slot m_slotMouseUp;
    CL_Slot m_slotMouseDown;
    CL_Slot m_slotAxisMove;
    int m_doubleClickTimer;

public:
    Widget(Widget * parent = 0,
           float x = 0.f,
           float y = 0.f,
           float width = 0.f,
           float height = 0.f);
    virtual ~Widget();

    void addWidget(Widget * widget, bool pushBack = true);

    void setLayout(LayoutType layout);

    // only for non-float layout
    void setSpacing(float hspacing, float vspacing);
    void setHSpacing(float hspacing);
    void setVSpacing(float vspacing);

    // only for Float layout
    void setAutoResize(bool autoResize);

    void setTitle(String & title);
    void setTitle(String * title);
    String & getTitle();

    void setVisible(bool visible);
    bool visible();

    // 0xFF means fully visible
    void setAlpha(int alpha);

    void setMouseCursor(Sprite * mouseCursor);

    void setViewPort(float x, float y, float width, float height);
    void setViewPort(Rect & rect);

    void setSelectable(bool selectable = true);

    enum InputState
    {
        Released,
        RollOver,
        Pressed
    } m_state;
    void setState(InputState state);

    // slots
    sigslot::signal0<> onPress;
    sigslot::signal0<> onRelease;
    sigslot::signal0<> onClick;
    sigslot::signal0<> onDoubleClick;

    virtual void update();
protected:
    virtual void draw();
    void enableInputEvents();
    virtual void inputEvent(const CL_InputEvent & event, const CL_InputState &);
};

}
