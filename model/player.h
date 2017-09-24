#include <iostream>
#include <string>
#include "piece.h"
#include "normalPiece.h"
#include "playerType.h"
#include <vector>
#include <memory>
#include <algorithm>

#pragma once

namespace draughts
{
    namespace model
    {
			class player
			{
				private:
					std::string _name;
					int _score;
					std::vector<std::unique_ptr<piece>> _pieces;
					playerType _id;
					int playernum;
				public:
					player(std::string name) : _name(name),_score(0),playernum(0)
					{
							_pieces.reserve(12); //reserve 12 pieces for this vector
					}
					bool checkPiece(int sX,int sY)
					{
						for(auto& ps : _pieces)
						{
							if(ps->getX()==sX && ps->getY()==sY)
							{
								return true;
							}
						}
						return false;
					}
					
					void removePiece(int x,int y) //remove piece
					{
						for(auto & ps : _pieces)
						{
							if(ps->getX()==x && ps->getY()==y)
							{
								//ps->setX(0);
								//ps->setY(0);
								_pieces.erase(std::remove(_pieces.begin(),_pieces.end(),ps),_pieces.end());
								//ps.reset(nullptr); //remove the ptr. tested receive segmenation fault
								break;
							}
						}
					}
					
					void updatePieceLocation(int sx,int sy,int ex,int ey) //update to the new location
					{
						for(auto & ps : _pieces)
						{
							if(ps->getX()==sx && ps->getY()==sy)
							{
								ps->setX(ex);
								ps->setY(ey);
								break;
							}
						}
					}
					bool movePiece(int sX,int sY,int eX,int eY); //move the specified piece
					std::vector<std::unique_ptr<piece>>& getPieces(){return _pieces;}
					void setPieces(); //initialize the pieces at the start based on the color
					char getPiece(int x,int y); // get the token 
					void setPlayerType(playerType id){_id=id;} //set playerType 
					int getPlayernum(){return playernum;} //get the player number
					void setPlayernum(int num){playernum=num;}//set the playernum
					std::string getName(){return _name;} //get the player name
					int& getScore(){return _score;} //get the current Score
			};
	}
}