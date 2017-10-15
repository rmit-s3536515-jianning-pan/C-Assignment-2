/***********************************************************************
 * COSC1254 - Programming Using C++
 * Semester 2 2017 Assignment #2
 * Full Name        : Yixuan Zhang, Jianning Pan
 * Student Number   : s3380293, s3536515
 * Course Code      : COSC1254
 **********************************************************************/
 
#include "main_menu.h"
#include "../nc_controller/command.h"
#include "../nc_controller/controller.h"

const std::vector<std::string> draughts::ncview::main_menu::strings = {
    "Add Player to the system",  
    "Play Game", "Exit Game"
};

draughts::ncview::main_menu::main_menu(void)
    : menu("English Draughts", strings, 
        draughts::nc_controller::controller::controller::get_instance()
            ->get_main_menu_commands())
{
}

draughts::ncview::main_menu::~main_menu(void)
{
}
