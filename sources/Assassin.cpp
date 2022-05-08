#include "Assassin.hpp"
#include "Game.hpp"
#include <string>
#include <iostream>
using namespace std;

namespace coup {
    Assassin::Assassin (Game &g, string s) : Player(g,s) {
        this->game = &g;
        this->name = s;
        this->money = 0;
        (*this->game).addPlayer(s);

    }

    void coup::Assassin::coup(Player &p) {
        if (this->money >= 7) {
            this->last_oper = "coup";
            this->money-=7;
        } else {
            if (this->money >= 3) {
                this->last_oper = "coup3";
                this->money-=3;
            } else {
                throw "Not enough money";
            }
        }
        void * ptr = &p;
        this->game->remove_player(p.get_name());
        this->game->set_last_coup(ptr);
    }
    
}