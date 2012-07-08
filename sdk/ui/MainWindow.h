#pragma once

#include "Widget.h"
#include "SubWindow.h"
#include <map>
#include "../graphics/Sprite.h"
#include "misc/String.h"

namespace sdk {

class MainWindow : public Widget
{
    static MainWindow * instance;
    static std::map<String, SubWindow *> m_subWindows;

    bool m_fullscreen;
    Sprite * m_sprite;

    SubWindow * m_currentSubWindow;

public:
    MainWindow();
    ~MainWindow();

    MainWindow * getInstance();

    void run();
    virtual void setup();

    void setFullscreen(bool fullscreen = true);
    void setSprite(Sprite * sprite);

    void addSubWindow(const char * name, SubWindow * window);
    void switchSubWindow(const char * name);

protected:
    virtual void draw();
    virtual void update();
};

}
