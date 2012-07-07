#include "Common.h"

extern "C" {
    #include <unistd.h>
    #include <libgen.h>
}

namespace sdk {

CommonClass::CommonClass()
{
    m_setupCore = new CL_SetupCore;
    m_setupDisplay = new CL_SetupDisplay;
    m_setupOpenGl1 = new CL_SetupGL1;
    m_setupSwrender = new CL_SetupSWRender;
    m_ic = 0;
    m_gc = 0;
    m_dt = 0;
    
    String dirname(getExecDir());
    if (chdir(dirname.c_str()) != 0) {
        throw CL_Exception("Cannot change directory to ``" + dirname + "''");
    }
}

CommonClass::~CommonClass()
{
    delete m_setupCore;
    delete m_setupDisplay;
    delete m_setupOpenGl1;
    delete m_setupSwrender;
}

void CommonClass::setGraphicContext(CL_GraphicContext * gc)
{
    m_gc = gc;
}

void CommonClass::setInputContext(CL_InputContext * ic)
{
    m_ic = ic;
}

CL_GraphicContext * CommonClass::getGraphicContext()
{
    return m_gc;
}

CL_InputContext * CommonClass::getInputContext()
{
    return m_ic;
}

void CommonClass::setDt(int dt)
{
    m_dt = dt;
}

int CommonClass::getDt()
{
    return m_dt;
}

String CommonClass::getExecDir()
{
    ssize_t len = -1;
    char buf[1024];
    char * result;
    if ((len = readlink("/proc/self/exe", buf, sizeof(buf)-1)) != -1) {
        buf[len] = '\0';
        result = dirname(buf);
    } else {
        return String(".");
    }
    return String(result);
}

}
