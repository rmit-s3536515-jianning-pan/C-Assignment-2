/***********************************************************************
 * COSC1254 - Programming Using C++
 * Semester 2 2017 Assignment #2
 * Full Name        : Yixuan Zhang, Jianning Pan
 * Student Number   : s3380293, s3536515
 * Course Code      : COSC1254
 **********************************************************************/
 
#include "window.h"
#include "ui.h"
#include "../model/model.h"
#include "../nc_controller/command.h"

draughts::ncview::window::window(void) 
    : view(draughts::ncview::ui::get_instance()), 
    themodel(draughts::model::model::get_instance())
{
}

std::string draughts::ncview::window::get_input(
        const std::string& prompt)
{
    std::string input;
    bool success = false;
    while(!success){
        std::cout << prompt + ": ";
        try{
            std::getline(std::cin, input);
            if(input.empty()){
                if(std::cin.eof()){
                    std::cin.clear();
                }
                throw input_cancelled();
            }
            success = true;
        }
        catch(input_cancelled & ic)
        {
            throw;
        }
    }
    return input;
}
