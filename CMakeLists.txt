CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
project(As2)
ADD_EXECUTABLE(As2 main_noncurses.cpp ncview/ui.cpp ncview/window.cpp ncview/player_selection_window.cpp
 ncview/menu.cpp ncview/main_menu.cpp ncview/game_window.cpp ncview/add_player_window.cpp nc_controller/controller.cpp nc_controller/command.cpp
 model/model.cpp)
SET(CMAKE_CXX_FLAGS "-std=c++14 -Wall -pedantic -g -O3")
SET(CMAKE_CXX_COMPILER "/opt/rh/devtoolset-6/root/usr/bin/g++")