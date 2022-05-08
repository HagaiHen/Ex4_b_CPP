#include "Captain.hpp"
#include "Duke.hpp"
#include "Contessa.hpp"
#include <iostream>

namespace coup {
    void coup::Captain::block (Player &c) {
        if (c.get_last_oper() != "steal") {
            throw "Can't reject";
        } else {
            c.dec();
            c.dec();
            c.get_steal_from()->inc();
            c.get_steal_from()->inc();
        }
    }
    void coup::Captain::steal (Player &p) {
        
        if (p.coins() >= 2) {
            p.dec();
            p.dec();
            this->money += 2;
            this->last_oper = "steal";
            this->steal_from = &p;
            this->game->inc();
        } else {
            throw "Not enough money";
        }
    }
    Captain::Captain (Game &g, string s) : Player(g,s) {
        this->game = &g;
        this->name = s;
        this->money = 0;
        (*this->game).addPlayer(s);
    }
}