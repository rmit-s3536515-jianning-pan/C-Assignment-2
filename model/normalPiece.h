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
							dir = direction::DOWN;
						}
						else if(_id==playerType::WHITE)
						{
							token = 'o';
							dir = direction::UP;
						}
					
				}
					  bool move(int sX,int sY,int eX,int eY) override
					{
						if(!(eX>0&&eX<9) || !(eY>0 &&eY<9)) return false;
						if(sX+static_cast<int>(dir)==eX){ //it is going correct direction
							if(abs(eY-sY)==1){ // if it is 1, it means moving diagonaly
								//x = eX; //change the x location to new X location
								//y = eY; //change the y location to new y location
								 std::cout <<"in the piece class , valid move" <<std::endl;
								 
								return true; //this is a valid move
							}
							std::cout <<"in the piece class , Notvalid move" <<std::endl;
						}
						return false;
						
					}
					
					
			};
	}
	
}
