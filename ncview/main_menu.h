/***********************************************************************
 * COSC1254 - Programming Using C++
 * Semester 2 2017 Assignment #2
 * Full Name        : Yixuan Zhang, Jianning Pan
 * Student Number   : s3380293, s3536515
 * Course Code      : COSC1254
 **********************************************************************/
 
#include "menu.h"

#pragma once

namespace draughts
{
    namespace ncview
    {
        class main_menu : public menu
        {
            static const std::vector<std::string> strings;
            public:
                main_menu(void);
                virtual ~main_menu(void);
        };
    }
}
