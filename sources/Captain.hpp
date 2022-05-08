//#include "Player.hpp"
#include "Game.hpp"
#include "Contessa.hpp"
#include "Duke.hpp"
#pragma once

namespace coup {

    class Captain : public Player {

        public:
            Captain (Game &g, string s);
            void block (Player &p);
            void steal (Player &p);
            string role() const { return string("Captain"); };
            

    };
    
}