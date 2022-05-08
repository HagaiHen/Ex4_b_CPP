#include "Player.hpp"
#pragma once


namespace coup {

    class Assassin : public Player {

        
        public:
            Assassin (Game &g, std::string s);   
            string role() const {return string("Assassin"); };
            void coup(Player &p);   

    };
    
}