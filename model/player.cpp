#include "player.h"

bool draughts::model::player::movePiece(std::unique_ptr<player>& player2, int sX,int sY,int eX,int eY)
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
									 if(!checkPiece(eX,eY)){
										 if(player2->checkPiece(eX,eY))//the locations has enemy piece
											{
												int nx = eX-sX;
												int ny = eY-sY;
												int npx = eX + nx;
												int npy = eY + ny;
												if(player2->checkPiece(npx,npy) || checkPiece(npx,npy))//if the new position is not empty
												{ //not able to move
													return false;
												}
												else{
													if(!isBeyondBoard(npx,npy))//if within the board
													{
														player2->removePiece(eX,eY);
														updatePieceLocation(sX,sY,npx,npy); //it is jump over enemy piece
														_score++;
													}
													else return false; //not inside the board 
													
													//below code is to check if it has multiple jump 
													if(isPieceAKing(npx,npy)) // if the piece is a king
													{std::cout << "both side \n";
														if(checkTopLeftForJumping(player2,npx,npy)  || checkTopRightForJumping(player2,npx,npy)
															|| checkBotLeftForJumping(player2,npx,npy) || checkBotRightForJumping(player2,npx,npy))
														{
															return false;
														}
													}
													else if(isBlack()){
														std::cout << "Black side \n";
															if(checkBotLeftForJumping(player2,npx,npy) || checkBotRightForJumping(player2,npx,npy))
														{
															std::cout <<"inside the black side \n";
															return false; 
														}
														
													}
													else if(isWhite()){
														std::cout <<"white side \n";
														if(checkTopLeftForJumping(player2,npx,npy) || checkTopRightForJumping(player2,npx,npy))
														{
															return false; 
														}
													
													}
											
												}
											}
											else{ // if no piece in both player, it is simple move
												updatePieceLocation(sX,sY,eX,eY);
												
											}
											return true;
									 }
							 } 
							 std::cout <<"correct move" <<std::endl;
								 break;// since already found the location , break out the loop
						 }
				} 
		return false;
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