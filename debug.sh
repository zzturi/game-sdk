#!/bin/sh

time (cmake CMakeLists.txt && make) && gdb --eval-command=r example/hello
