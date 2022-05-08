#include <string>
using namespace std;
#include "Player.hpp"

namespace coup {

    int turns = 0;
    
    Player::Player (Game &g, string s) {
        this->game = &g;
        this->name = s;
        this->money = 0;
        //(*this->game).addPlayer(s);
    }

    void coup::Player::income() {
        if (this->money >= 10) {
            throw "You have to do coup";
        }
        if (this->name != this->game->turn()) {
            throw "Not your turn";
        }
        this->money++;
        turns++;
        this->game->inc();
        this->last_oper = "income";

    }
    int coup::Player::coins() {
        return this->money;
    }
    void coup::Player::foreign_aid() {
        if (this->name != this->game->turn()) {
            throw "Not your turn";
        }
        if (this->money >= 10) {
            throw "You have to do coup";
        }
        this->money += 2;
        turns++;
        this->game->inc();
        this->last_oper = "foreign_aid";

    }
    // string coup::Player::role() {
    //     string s;
    //     return s;
    // }
    void coup::Player::coup  (Player &p) {
        if (this->money < 7) {
            throw "Not enough money";
        } else {
            this->money-=7;
        }
        void * ptr = &p;
        this->game->remove_player(p.get_name());
        this->game->set_last_coup(ptr);
        this->last_oper = "coup";
        this->game->inc();
    }

    int coup::Player::num_of_turns() {
        return turns;
    }

    string coup::Player::get_last_oper() {
        return this->last_oper;
    }

}