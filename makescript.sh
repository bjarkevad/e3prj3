#!/bin/bash
qmake2 && qmake2 e3prj3.pro CXXFLAGS+=TARGET && make -j4 && scp e3prj3 root@10.9.8.2:e3prj3
