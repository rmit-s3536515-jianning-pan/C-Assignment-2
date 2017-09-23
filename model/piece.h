#include <iostream>
#include "playerType.h"
#pragma once

namespace draughts
{
    namespace model
    {
		class piece
		{
			protected:
				int x;
				int y;
				char token;
				playerType _id;
			public:
				piece(int _x,int _y) : x(_x),y(_y),token('\0')
				{
					
				}
				
				virtual void move(int,int,int,int);
				virtual char draw(int,int);
		};
	}
	
}
