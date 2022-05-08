#include "Player.hpp"
#include "Assassin.hpp"
#pragma once


namespace coup {

    class Contessa : public Player {

        public:
            Contessa (Game &g, string s);
            void block(Player &p);
            string role() const {return string("Contessa"); };

    };
}