#include "Duke.hpp"
#include "Assassin.hpp"
#include <iostream>

namespace coup {
    
    void coup::Duke::block(Player &p) {
        if (p.get_last_oper() == "foreign_aid") {
            p.dec();
            p.dec();
        } else {
            throw "Can't reject";
        }
    }

    void coup::Duke::tax() {
        this->money+=3;
        this->game->inc();
    }
    
    Duke::Duke (Game &g, string s) : Player(g,s) {
        this->game = &g;
        this->name = s;
        this->money = 0;
        (*this->game).addPlayer(s);
        
    }
}