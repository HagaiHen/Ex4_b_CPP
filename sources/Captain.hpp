//#include "Player.hpp"
#include "Game.hpp"
#include "Contessa.hpp"
#include "Duke.hpp"
#pragma once

namespace coup {

    class Captain : public Player {

        public:
            Captain (Game &g, const string &s);
            void block (Player &c) const;
            void steal (Player &p);
            string role() const { return string("Captain"); };
            

    };
    
}