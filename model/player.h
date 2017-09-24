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
					
					bool movePiece(int sX,int sY,int eX,int eY);
					 
					void setPieces(); //set the pieces 
					char getPiece(int x,int y);
					void setPlayerType(playerType id){_id=id;}
					int getPlayernum(){return playernum;} //get the player number
					void setPlayernum(int num){playernum=num;}//set the playernum
					std::string getName(){return _name;} //get the player name
					int& getScore(){return _score;} //get the current Score
			};
	}
}