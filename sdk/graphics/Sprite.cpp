#include "Sprite.h"
#include "../misc/Common.h"
#include "../misc/ResourceManager.h"

namespace sdk {

Sprite::Sprite(const CL_StringRef &fullname)
    : CL_Sprite(*GC, fullname, &RC)
{
    lastWidth = 0;
    lastHeight = 0;
}

void Sprite::update()
{
    if (lastWidth != width() || lastHeight != height()) {
        lastWidth = width();
        lastHeight = height();
        set_scale(width() / get_width(), height() / get_height());
    }

    CL_Sprite::update();
}

}
