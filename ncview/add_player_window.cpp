/***********************************************************************
 * COSC1254 - Programming Using C++
 * Semester 2 2017 Assignment #2
 * Full Name        : Yixuan Zhang, Jianning Pan
 * Student Number   : s3380293, s3536515
 * Course Code      : COSC1254
 **********************************************************************/
 
#include "add_player_window.h"
#include "ui.h"
#include "../model/model.h"
#include "../nc_controller/command.h"

void draughts::ncview::add_player_window::activate(void)
{
    std::string name;
    bool success = false;
    std::string recv;

    while(!success){
        try {
            name = window::get_input(
               "Please enter the name for the new player"  
            );
			draughts::model::model * themodel = 
             draughts::model::model::get_instance();
			if(themodel->getPlayers().empty()){
				success = true;
			}
			else{
				for(auto& p : themodel->getPlayers())
				{
					if(p->getName()==name) //check the duplicate name
					{
						success= false;
						break;
					}
					else{
						success = true;
						}
				}
			}
            if(success) themodel->add_player(name); //if no duplicate name , add player
		    
          //  success = true;
        }
        catch(std::exception& ex)
        {
            std::cerr << ex.what() << std::endl;
            return;
        }
    }
    std::cout << "Successfully added " << name << " to the player roster."
        << std::endl;
    std::cout << "Press <enter> to continue: " << std::endl;
    std::cin.get();
    view->main_menu();
}
