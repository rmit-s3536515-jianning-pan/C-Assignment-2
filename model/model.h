#include <vector>
#include <memory>
#include <utility>
#include <iostream>
#include <sstream>
#include <map>
#include <thread>
#include <chrono>
#include "player.h"
#include "piece.h"
#include "playerType.h"

#pragma once

namespace draughts
{
    namespace model
    {
        class model
        {
            static std::unique_ptr<model> instance;
			
			std::vector<std::unique_ptr<player>> players; //store 2 player 
			
			std::vector<std::unique_ptr<player>> selected; // store the selected players
			
			int currentId; //track for the current player
			
            model(void);
            bool player_exists(const std::string&);
			
            public:
			void setCurrentId(const int& id){currentId=id;} //set the current player number
			std::vector<std::unique_ptr<player>>& getSelectedPlayers(){return selected;} //get the selected players
			std::vector<std::unique_ptr<player>>& getPlayers(){return players;} // get the players
            void start_game(int, int);
            char get_token(int,int);
            void make_move(int, int, int, int, int);

            void add_player(const std::string& );
            int get_player_score(int);
            int get_current_player(void);
            std::string get_player_name(int);
            std::map<int, std::string> get_player_list(void) const;
            int get_winner();
            int get_width();
            int get_height();
            static model * get_instance(void);
            static void delete_instance(void);
            virtual ~model(void);
        };
    }
}
