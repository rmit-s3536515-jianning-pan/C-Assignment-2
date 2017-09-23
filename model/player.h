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
					
					void movePiece(int sX,int sY,int eX,int eY)
					{
						std::cout <<"in the player class : move" << sX << sY<< eX << eY<<std::endl;
						 //bool correct = false;
						 for(auto & p : _pieces)
						 {
							 if(p->getX()==sX && p->getY()==sY) //if the start location is found 
							 {
								 p->move(sX,sY,eX,eY); //check if it is valid move
								 /*
								 if(correct){
									 //_pieces.erase(std::remove(_pieces.begin(),_pieces.end(),p),_pieces.end());
									 //_pieces.push_back(std::make_unique<normalPiece>(eX,eY,_id));
									// p.reset(new normalPiece(eX,eY,_id));
									 
								 }*/
								 std::cout <<"correct move" <<std::endl;
								 break;// since already found the location , break out the loop
							 }
						 }
						 //return correct;
					 }
					 
					void setPieces() //set the pieces 
					{
						if(_id == playerType::BLACK){
								for(int i=1;i<=3;++i)
								{
									for(int j=1; j<=8;++j)
									{
										if(i%2!=0 && j%2==0){
											
											_pieces.push_back(std::make_unique<normalPiece>(i,j,_id));
										}
										else if(i%2==0 && j%2!=0)
										{
											_pieces.push_back(std::make_unique<normalPiece>(i,j,_id));
										}
									}
								}
							}
							else if(_id==playerType::WHITE)
							{
								for(int i=6;i<=8;++i)
								{
									for(int j=1; j<=8;++j)
									{
										if(i%2!=0 && j%2==0){
											
											_pieces.push_back(std::make_unique<normalPiece>(i,j,_id));
										}
										else if(i%2==0 && j%2!=0)
										{
											_pieces.push_back(std::make_unique<normalPiece>(i,j,_id));
										}
									}
								}
							}
					}
					char getPiece(int x,int y){
				//char token;
						char token;
						bool found = false;
						for(auto& p : _pieces)
						{
							if(x==p->getX() && y==p->getY()) // same x and y
							{
								token = p->getToken();
								found = true;
								break;
							}
						}
						if(found) return token;
						
						return '\0';
					}
					void setPlayerType(playerType id){_id=id;}
					int getPlayernum(){return playernum;} //get the player number
					void setPlayernum(int num){playernum=num;}//set the playernum
					std::string getName(){return _name;} //get the player name
					int& getScore(){return _score;} //get the current Score
			};
	}
}