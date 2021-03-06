#include "Game.hpp"
#include "Ambassador.hpp"
#include <string>
#include "Duke.hpp"
#include "Assassin.hpp"
#include <iostream>

using namespace std;

namespace coup {

    
    void coup::Ambassador::transfer (Player &p1, Player &p2) {
        if (p1.coins() > 0) {
            p1.dec();
            p2.inc();
            this->game->inc();
            this->game->next_turn();
        } else {
            
            throw "you can transfer";
        }
        
    }

    void Ambassador::block (Captain &c) const{
        this->role();
        if (c.get_last_oper() == "steal") {
            c.dec();
            c.dec();
            c.get_steal_from()->inc();
            c.get_steal_from()->inc();
            
        } else {
            throw "Can't reject";
        }
    }

    Ambassador::Ambassador (Game &g, const string &s) : Player(g,s) {
        this->game = &g;
        this->name = s;
        this->money = 0;
        (*this->game).addPlayer(s);

    }
}