#include "Contessa.hpp"
#include "Assassin.hpp"
#include "Game.hpp"
#include <string>
#include <iostream>




namespace coup {
    void coup::Contessa::block(Player &p) {
        if (p.get_last_oper() != "coup3" || p.role() != "Assassin") {
            cout << p.get_last_oper() << endl;
            cout << p.role() << endl;
            throw "cant reject";
        } else {
            p.inc();
            p.inc();
            p.inc();
            Player * tmp = (Player*)this->game->get_last_coup();
            //this->game->addPlayer_after(tmp->get_name());
        }

    }

    Contessa::Contessa (Game &g, string s) : Player(g,s) {
        this->game = &g;
        this->name = s;
        this->money = 0;
        (*this->game).addPlayer(s);
    }
}