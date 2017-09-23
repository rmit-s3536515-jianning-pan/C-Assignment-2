#include <iostream>
#include "piece.h"
#include "../direction.h"
#pragma once

namespace draughts
{
    namespace model
    {
			class normalPiece : public piece
			{
				private:
					direction dir;
				public:
				normalPiece(int _x,int _y,playerType id) : piece(_x,_y,id)
				{
						if(_id==playerType::BLACK)
						{
							token = 'x';
							dir = direction::DOWN;
						}
						else if(_id==playerType::WHITE)
						{
							token = 'o';
							dir = direction::UP;
						}
					
				}
					  void move(int sX,int sY,int eX,int eY) override
					{
						if(sX+static_cast<int>(dir)==eX){ //it is going correct direction
							if(abs(eY-sY)==1){ // if it is 1, it means moving diagonaly
								x = eX; //change the x location to new X location
								y = eY; //change the y location to new y location
								 std::cout <<"in the piece class , valid move" <<std::endl;
								//return true;
							}
							std::cout <<"in the piece class , Notvalid move" <<std::endl;
						}
						//return false;
						
					}
					
			};
	}
	
}
