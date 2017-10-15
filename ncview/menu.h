/***********************************************************************
 * COSC1254 - Programming Using C++
 * Semester 2 2017 Assignment #2
 * Full Name        : Yixuan Zhang, Jianning Pan
 * Student Number   : s3380293, s3536515
 * Course Code      : COSC1254
 **********************************************************************/
 
#include "window.h"
#include <vector>
#include <memory>
#include <string>
#include <iostream>

#pragma once

namespace draughts
{
    namespace ncview
    {
        class menu : public window
        {
            std::string title;
            std::vector<std::string> menu_text;
            command_vector menu_commands;
            public:
                menu(const std::string&, const std::vector<std::string>&, 
                    command_vector);
                menu(void);
                void set_title(const std::string&);
                void set_text(const std::vector<std::string>&);
                void set_actions(command_vector&);
                virtual void activate(void) override;
                virtual ~menu(void){}
        };
    }
}
