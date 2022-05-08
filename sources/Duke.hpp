#include "Player.hpp"
#include "Assassin.hpp"
#pragma once
#include "Game.hpp"
#include <string>

namespace coup {

    class Duke : public Player {

        
        public:
            void block(Player &p);
            void tax();
            Duke (Game &g, std::string s);
            string role() const {return string("Duke"); };

    };
    
}