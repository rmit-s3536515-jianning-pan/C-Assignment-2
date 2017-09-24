#include "player.h"

bool draughts::model::player::movePiece(int sX,int sY,int eX,int eY)
{
	std::cout <<"in the player class : move" << sX << sY<< eX << eY<<std::endl;
						 bool correct = false;
						 for(auto & p : _pieces)
						 {
							 if(p->getX()==sX && p->getY()==sY) //if the start location is found 
							 {
								 correct = p->move(sX,sY,eX,eY); //check if it is valid move
								 if(correct) //if it is valid move , then check the finish location 
								 {
									 bool found = false;
									 for(auto& piece : _pieces)
									 {
										 if(piece->getX()==eX && piece->getY()==eY) //check if end x and y exists in the _pieces
										 {
											 found = true; //if the end location is found 
											 break;
										 }
									 }
									 if(found==false) // if the end location is not found
									 {
										 p->setX(eX);
										 p->setY(eY);
										 return true;
									 }
								 }
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
						 return false;
						 //return correct;

}

void draughts::model::player::setPieces()
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

char draughts::model::player::getPiece(int x,int y)
{
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