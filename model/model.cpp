#include "model.h"

#include <algorithm>
std::unique_ptr<draughts::model::model> draughts::model::model::instance =
nullptr;

draughts::model::model::model(void) 
{
}

draughts::model::model * draughts::model::model::get_instance(void)
{
    if(instance == nullptr)
    {
        instance = std::unique_ptr<model>(new model);	
    }
    return instance.get();    
}

int draughts::model::model::get_player_score(int playernum)
{
	int scores = 0;
	for(auto & p : selected)
	{
		if(p->getPlayernum()==playernum){
			scores = p->getScore();
		}
	}
    return scores;
}

void draughts::model::model::start_game(int plr1, int plr2) // ​starts​ ​a​ ​new​ ​game​ ​with​ ​the​ ​specified​ ​player​ ​ids
{
	int count =1;
	for(auto& p : players)
	{
		if(count==plr1)
		{
			p->setPlayernum(plr1);
			p->setPlayerType(playerType::BLACK);
			p->setPieces();
			selected.push_back(std::move(p));
			
		}else if(count ==plr2)
		{
			p->setPlayernum(plr2);
			p->setPlayerType(playerType::WHITE);
			p->setPieces();
			selected.push_back(std::move(p));
		}
		count++;
	}
	//std::cout << selected.size() << std::endl;
	instance ->setCurrentId(plr1);
}

int draughts::model::model::get_winner() //if the player get 12 score in total
{
	if(get_player_score(currentId)==12){
		return 1;
	}
	else
	{
	for(auto & p : selected)
	{
		if(p->getPlayernum()!=currentId){
			if(p->getScore()==12)
			{
				return 1;
			}
		}
	}
	}
		
    return EOF;
}

std::string draughts::model::model::get_player_name(int id)
{
	std::string name;
	for(auto & p : selected)
	{
		if(p->getPlayernum()==id){
			name = p->getName();
		}
	}
    return name;
}

char draughts::model::model::get_token(int x ,int y)
{
	
	char t;
	
	for(auto & p : selected)
	{
		t = p->getPiece(x,y); //if found , will have token
		
		if(t!='\0') // token is  empty
		{
			break;
		}
		
		
	}
	return t;
}

void draughts::model::model::make_move(int playernum,
        int startx, int starty, int endx, int endy)
{
	int anotherPlayernum = 0;
	bool found = false;
	for(auto& p : selected){
		if(p->getPlayernum()==playernum) //if the player number is equal to the current player
		{
				for(auto& s : selected) //wanna check the oppoent's pieces
				{
					//std::cout << "check oppoent's pieces"<<std::endl;
					if(s->getPlayernum()!=playernum)
						found = p->movePiece(s,startx,starty,endx,endy);
				}
		}
		else{
			anotherPlayernum = p->getPlayernum();
		}
	}
	if(found){
		if(get_player_score(playernum)!=12){
			currentId = anotherPlayernum;
		}
	}else{
		std::cout<< std::endl << "Invalid Move, Please choose another coordinate!" <<std::endl;
	}
}

void draughts::model::model::add_player(const std::string& p) // modified
{
	
	players.push_back(std::make_unique<player>(p));
}

bool draughts::model::model::player_exists(const std::string& pname)
{
    return false;
}

int draughts::model::model::get_current_player(void)
{
    return currentId;
}

std::map<int, std::string> draughts::model::model::get_player_list(void) 
    const
{
    std::map<int, std::string> nameslist;
	int count = 0;
	for(auto& p : instance->getPlayers())
	{
		nameslist.insert(std::pair<int,std::string>(++count,p->getName()));
	}
	
    return nameslist;
}

void draughts::model::model::delete_instance(void)
{
    instance.reset(nullptr);
}


int draughts::model::model::get_width()
{
    return 8;
}

int draughts::model::model::get_height()
{
    return 8;
}

draughts::model::model::~model(void)
{
}

