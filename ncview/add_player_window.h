/***********************************************************************
 * COSC1254 - Programming Using C++
 * Semester 2 2017 Assignment #2
 * Full Name        : Yixuan Zhang, Jianning Pan
 * Student Number   : s3380293, s3536515
 * Course Code      : COSC1254
 **********************************************************************/
 
#include "window.h"
#pragma once
namespace draughts
{
    namespace ncview
    {
        class add_player_window : public window
        {
            public:
            virtual void activate(void) override;
            virtual ~add_player_window(void){}
        };
    }
}
