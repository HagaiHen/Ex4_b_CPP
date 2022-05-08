#include "Game.hpp"
#include "Player.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include <string>
#include "Captain.hpp"
#pragma once

namespace coup {

    class Ambassador : public Player {

        public:
            Ambassador (Game &g, string s); 
            void transfer (Player &p1, Player &p2);
            void block(Captain &c);
            string role() const {return string("Ambassador"); };         
    };
    
}