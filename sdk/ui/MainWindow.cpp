#include "MainWindow.h"
#include "../misc/Common.h"
#include <ClanLib/Core/System/keep_alive.h>

namespace sdk {

std::map<String, SubWindow *> MainWindow::m_subWindows;
MainWindow * MainWindow::instance = 0;

MainWindow::MainWindow()
{
    instance = this;
    m_fullscreen = false;
    m_sprite = 0;
    m_currentSubWindow = 0;
}

MainWindow::~MainWindow()
{
    for (auto it = m_subWindows.begin(); it != m_subWindows.end(); ++it)
        delete it->second;

    m_subWindows.clear();
}

MainWindow * MainWindow::getInstance()
{
    return instance;
}

void MainWindow::setFullscreen(bool fullscreen)
{
    m_fullscreen = fullscreen;
}

void MainWindow::run()
{
    Common::getInstance();  // initialize rendering

    CL_DisplayWindow window(getTitle(),
                            (int)width(),
                            (int)height(),
                            m_fullscreen);

    CL_Rect g = window.get_geometry();

    Common::getInstance().setSize(g.get_width(), g.get_height());
    setSize(g.get_width(), g.get_height());
    setWidth(g.get_width());

    CL_GraphicContext gc = window.get_gc();
    CL_InputContext ic = window.get_ic();
    Common::getInstance().setGraphicContext(&gc);
    Common::getInstance().setInputContext(&ic);
    setup();

    /*CL_Slot slotQuit = window.sig_window_close().connect(
        this,
        &MainWindow::onClose
    );*/

    uint currentTime = 0;
    int dt = 0;
    while (true) {
        currentTime = CL_System::get_time();
        if (ic.get_keyboard().get_keycode(CL_KEY_ESCAPE))
            break;
        update();
        window.flip(0);
        CL_KeepAlive::process();
        CL_System::sleep(1);
        dt = (int)(CL_System::get_time() - currentTime);
        Common::getInstance().setDt(dt);
    }
}

void MainWindow::setup()
{
}

void MainWindow::draw()
{
    if (!m_sprite)
        CL_Draw::fill(*GC, 0.f, 0.f, width(), height(), CL_Colorf::grey);
    else
        m_sprite->draw(*GC, x(), y());

    //Widget::draw();
    //m_currentSubWindow->draw();
}

void MainWindow::update()
{
    Widget::update();
    m_currentSubWindow->update();
}

void MainWindow::setSprite(Sprite * sprite)
{
    m_sprite = sprite;
}

void MainWindow::addSubWindow(const char * name, SubWindow * window)
{
    m_subWindows[name] = window;
    if (!m_currentSubWindow)
        m_currentSubWindow = window;
}

void MainWindow::switchSubWindow(const char * name)
{
    m_currentSubWindow = m_subWindows[name];
}

}
