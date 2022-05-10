#include "Player.hpp"
#include "Assassin.hpp"
#pragma once
#include "Game.hpp"
#include <string>

namespace coup {

    class Duke : public Player {

        
        public:
            void block(Player &p) const;
            void tax();
            Duke (Game &g, const string &s);
            string role() const {return string("Duke"); };

    };
    
}