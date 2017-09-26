#include <iostream>
#include <string>
#include "piece.h"
#include "normalPiece.h"
#include "kingPiece.h"
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
					
					bool isPieceAKing(int sX,int sY)
					{
						for(auto& ps : _pieces)
						{
							if(ps->getX()==sX && ps->getY()==sY)
							{
								if(ps->isKing()){
									return true;
								}
								
							}
						}
						return false;
					}
					
					bool isBlack(){
						if(_id==playerType::BLACK) return true;
						else return false;
					}
					bool isWhite(){
						if(_id==playerType::WHITE) return true;
						else return false;
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
								_pieces.erase(std::remove(_pieces.begin(),_pieces.end(),ps),_pieces.end());
								break;
							}
						}
					}
					bool isBeyondBoard(int ex,int ey){
						if(!(ex>0&&ex<9) || !(ey>0 &&ey<9)) return true;
						else return false;
					}
					void updatePieceLocation(int sx,int sy,int ex,int ey) //update to the new location
					{
						if(isBeyondBoard(ex,ey)) return;
						for(auto & ps : _pieces)
						{
							if(ps->getX()==sx && ps->getY()==sy)
							{
								
								if(isPieceAKing(ex,ey)){
									ps->setX(ex);
									ps->setY(ey);
									return;
								}
								if(ex==1 || ex==8){
									removePiece(sx,sy);
									playerType pt;
									if(isBlack()) pt = playerType::BLACK;
									else pt = playerType::WHITE;
									
									_pieces.push_back(std::make_unique<kingPiece>(ex,ey,pt));
									
								}
								else{
									ps->setX(ex);
									ps->setY(ey);
								}
								
								break;
							}
						}
						
					}
					
					bool checkTopLeftForJumping(std::unique_ptr<player>& player2,int x,int y) //new position
					{
						if(isBeyondBoard(x,y)) return false;
						int dx = -1; 
						int dy = -1;
						if(checkPiece(x+dx,y+dy))
						{
							return false;
						}
						else if(player2->checkPiece(x+dx,y+dy))
						{
							int nx = x +dx + dx;
							int ny = y +dy + dy;
							if(isBeyondBoard(nx,ny)) return false;
							if(player2->checkPiece(nx,ny) || checkPiece(nx,ny))
							{
								return false;
							}
							else{
								return true;
							}
						}
						return false;
					}
					bool checkTopRightForJumping(std::unique_ptr<player>& player2,int x,int y) //new position
					{
						if(isBeyondBoard(x,y)) return false;
						int dx = -1; 
						int dy = 1;
						if(checkPiece(x+dx,y+dy))
						{
							return false;
						}
						else if(player2->checkPiece(x+dx,y+dy))
						{
							int nx = x +dx + dx;
							int ny = y +dy + dy;
							if(isBeyondBoard(nx,ny)) return false;
							if(player2->checkPiece(nx,ny) || checkPiece(nx,ny))
							{
								return false;
							}
							else{
								return true;
							}
						}
						return false;
					}
					bool checkBotLeftForJumping(std::unique_ptr<player>& player2,int x,int y) //new position
					{
						if(isBeyondBoard(x,y)) return false;
						int dx = 1; 
						int dy = -1;
						if(checkPiece(x+dx,y+dy))
						{
							return false;
						}
						else if(player2->checkPiece(x+dx,y+dy))
						{
							int nx = x +dx + dx;
							int ny = y +dy + dy;
							if(isBeyondBoard(nx,ny)) return false;
							if(player2->checkPiece(nx,ny) || checkPiece(nx,ny))
							{
								return false;
							}
							else{
								return true;
							}
							//return checkTopLeftForJumping(player2,x+dx,y+dy);
						}
						return false;
						//return true;
					}
					
					bool checkBotRightForJumping(std::unique_ptr<player>& player2,int x,int y) //new position
					{
						if(isBeyondBoard(x,y)) return false;
						int dx = 1; 
						int dy = 1;
						if(checkPiece(x+dx,y+dy))
						{
							return false;
						}
						else if(player2->checkPiece(x+dx,y+dy))
						{
							int nx = x +dx + dx;
							int ny = y +dy + dy;
							if(isBeyondBoard(nx,ny)) return false;
							if(player2->checkPiece(nx,ny) || checkPiece(nx,ny))
							{
								return false;
							}
							else{
								return true;
							}
						}
						return false;
					}
					bool movePiece(std::unique_ptr<player>& player2,int sX,int sY,int eX,int eY); //move the specified piece
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