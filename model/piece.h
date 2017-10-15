/***********************************************************************
 * COSC1254 - Programming Using C++
 * Semester 2 2017 Assignment #2
 * Full Name        : Yixuan Zhang, Jianning Pan
 * Student Number   : s3380293, s3536515
 * Course Code      : COSC1254
 **********************************************************************/
 
#include <iostream>
#include "playerType.h"
#include "../direction.h"
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
				direction dir;
			public:
				piece(int _x,int _y,playerType id) : x(_x),y(_y), _id(id),token('\0')
				{
					
				}
				
				bool isKing(){
					if(dir==direction::BOTH)
					{
						return true;
					}
					else return false;
				}
				int getX(){return x;}
				void setX(int newX){x=newX;}
				int getY(){return y;}
				void setY(int newY){y=newY;}
				void setToken(char t){token = t;}
				char getToken(){return token;}
				virtual bool move(int,int,int,int)=0;
				
				//virtual char draw()=0;
		};
	}
	
}
