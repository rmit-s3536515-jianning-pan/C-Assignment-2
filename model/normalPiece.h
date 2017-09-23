#include <iostream>
#include "piece.h"

#pragma once

namespace draughts
{
    namespace model
    {
			class normalPiece : public piece
			{
				public:
				normalPiece(int _x,int _y,playerType id) : piece(_x,_y,id)
				{
						if(_id==playerType::BLACK)
						{
							token = 'x';
						}
						else if(_id==playerType::WHITE)
						{
							token = 'o';
						}
					
				}
					  void move(int sX,int sY,int eX,int eY) override
					{
							
					}
					/*
					 char draw() override
					{
						if(_id==playerType::BLACK)
						{
							token = 'x';
						}
						else if(_id==playerType::WHITE)
						{
							token = 'o';
						}
						char p = token;
						
						return p;
					}*/
			};
	}
	
}
