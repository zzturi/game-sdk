#pragma once

#include "Singleton.h"

namespace sdk {

typedef Singleton<CL_ResourceManager> ResourceManager;

}

#define RC (::sdk::ResourceManager::getInstance())
