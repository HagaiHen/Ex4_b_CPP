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
        bool exist = false;
        for (size_t i =0; i < this->game->players().size(); i++) {
            if (this->game->players()[i] == p.get_name()) {
                exist = true;
            }
        }
        if (!exist) {
            throw "The player already dead";
        }
        if (this->money >= 7) {
            cout << "%" << endl;
            this->last_oper = "coup";
            this->money-=7;
            this->game->inc();
            this->game->next_turn();
        } else {
            if (this->money >= 3) {
                cout << "%" << endl;
                this->last_oper = "coup3";
                this->money-=3;
                this->game->inc();
                this->game->next_turn();
            } else {
                throw "Not enough money";
            }
        }
        //void * ptr = &p;
        this->game->remove_player(p.get_name());
        //this->game->set_last_coup(ptr);
        this->couped = &p;
        //this->game->next_turn();
    }
    
}