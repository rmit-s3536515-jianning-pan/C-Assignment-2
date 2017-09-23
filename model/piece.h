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
				playerType _id;
				char token;
			public:
				piece(int _x,int _y,playerType id) : x(_x),y(_y), _id(id),token('\0')
				{
					
				}
				int getX(){return x;}
				void setX(int newX){x=newX;}
				int getY(){return y;}
				void setY(int newY){y=newY;}
				char getToken(){return token;}
				virtual void move(int,int,int,int)=0;
				//virtual char draw()=0;
		};
	}
	
}
