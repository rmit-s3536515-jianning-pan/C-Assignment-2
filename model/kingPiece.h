#include <iostream>
#include "piece.h"
#pragma once

namespace draughts
{
    namespace model
    {
			class kingPiece : public piece
			{
				public:
				kingPiece(int _x,int _y,playerType id) : piece(_x,_y,id)
				{
					
						if(_id==playerType::BLACK)
						{
							token = 'X';
							
						}
						else if(_id==playerType::WHITE)
						{
							token = 'O';	
						}
						dir = direction::BOTH;
					
				}
					  bool move(int sX,int sY,int eX,int eY) override
					{
						if(!(eX>0&&eX<9) || !(eY>0 &&eY<9)) return false; //if goes beyond the board , return false
						if(abs(eX-sX)==1){ //it is going ny diagonaly and can go both direction
							if(abs(eY-sY)==1){ // if it is 1, it means moving diagonaly
								//x = eX; //change the x location to new X location
								//y = eY; //change the y location to new y location
								 //std::cout <<"in the piece class , valid move" <<std::endl;
								 
								return true; //this is a valid move
							}
							//std::cout <<"in the piece class , Notvalid move" <<std::endl;
						}
						return false;
						
					}
			};
	}
}