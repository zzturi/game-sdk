cmake_minimum_required(VERSION 2.8)

project(hello)

add_definitions(-std=c++0x -Isdk -O0 -g -Wall)

#set(CMAKE_MODULE_PATH  ${PROJECT_SOURCE_DIR}/cmake-extensions/ )
find_package(PkgConfig)

pkg_check_modules(CLANLIB clanCore-2.3 clanDisplay-2.3 clanGL1-2.3 clanApp-2.3
clanSWRender-2.3)

link_directories(
    ${CLANLIB_LIBRARY_DIRS}
)
include_directories(
    ${CLANLIB_INCLUDE_DIRS}
)

add_executable(example/hello
    example/hello.cpp
    example/MyMainWindow.cpp
    example/MyMainWindow.h
    sdk/ui/Widget.cpp
    sdk/ui/MainWindow.cpp
    sdk/ui/Button.cpp
    sdk/ui/MainWindow.h
    sdk/ui/Widget.h
    sdk/ui/Button.h
    sdk/misc/Singleton.h
    sdk/misc/String.h
    sdk/misc/Common.cpp
    sdk/misc/ResourceManager.h
    sdk/misc/Common.h
    sdk/misc/sigslot.h
    sdk/graphics/geometry.h
    sdk/graphics/Sprite.cpp
    sdk/graphics/Sprite.h
    sdk/graphics/geometry.cpp
)

target_link_libraries(example/hello
    ${CLANLIB_LIBRARIES}
)
