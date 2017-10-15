/***********************************************************************
 * COSC1254 - Programming Using C++
 * Semester 2 2017 Assignment #2
 * Full Name        : Yixuan Zhang, Jianning Pan
 * Student Number   : s3380293, s3536515
 * Course Code      : COSC1254
 **********************************************************************/
 
#include "ncview/ui.h"
#include "nc_controller/controller.h"
#include "model/model.h"

int main(void)
{
    draughts::ncview::ui * view = draughts::ncview::ui::get_instance();
    atexit(draughts::ncview::ui::delete_instance);
    atexit(draughts::nc_controller::controller::delete_instance);
    atexit(draughts::model::model::delete_instance);
    view->main_menu();
	
	
}
