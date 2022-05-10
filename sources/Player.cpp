#include <string>
using namespace std;
#include "Player.hpp"
#include "Game.hpp"
#include <iostream>

const int COST_OF_COUP = 7;
const int MAX_COINS = 10;
const int FIVE = 5;

namespace coup {

    int turns = 0;
    size_t n = 0;
    
    Player::Player (Game &g, const string &s) {
        this->game = &g;
        this->name = s;
        this->money = 0;
        // this->id = 0;
        this->id = this->game->id++;
        this->steal_from = NULL;
        this->couped = NULL;
        //(*this->game).addPlayer(s);
        if (this->id > FIVE || this->game->get_num_of_turns() > 0) {
            throw invalid_argument("Error");
        }
    }

    void coup::Player::income() {
        if (this->game->players().size() == 1) {
            throw invalid_argument("Error");
        }
        //cout << "HHH" << endl;
        if (this->money >= MAX_COINS) {
            throw "You have to do coup";
        }
        //cout << "HHH" << endl;
        if (this->name != this->game->turn()) {
            throw "Not your turn";
        }
        //cout << "HHH" << endl;
        this->money++;
        //turns++;
        this->game->inc();
        this->game->next_turn();
        this->last_oper = "income";
        //cout << "HHH" << endl;
    }
    int Player::coins() const {
        return this->money;
    }
    void coup::Player::foreign_aid() {
        if (this->game->players().size() == 1) {
            throw invalid_argument("Error");
        }
        if (this->name != this->game->turn()) {
            throw "Not your turn";
        }
        if (this->money >= MAX_COINS) {
            throw "You have to do coup";
        }
        this->money += 2;
        // turns++;
        this->game->inc();
        this->game->next_turn();
        this->last_oper = "foreign_aid";

    }
    
    void coup::Player::coup  (Player &p) {
        if (this->name != this->game->turn()) {
            throw "Not your turn";
        }
        bool exist = false;
        for (size_t i =0; i < this->game->players().size(); i++) {
            if (this->game->players()[i] == p.get_name()) {
                exist = true;
            }
        }
        if (!exist) {
            throw "The player already dead";
        }
        if (this->money < COST_OF_COUP) {
            throw "Not enough money";
        }
        
        this->money-=COST_OF_COUP;
        
        //cout << "%" << endl;
        //void * ptr = &p;
        this->game->remove_player(p.get_name());
        //this->game->set_last_coup(&p);
        this->last_oper = "coup";
        this->game->inc();
        this->game->next_turn();
        this->couped = &p;
        //cout << "end of cuop" << endl;
    }

    // int coup::Player::num_of_turns() {
    //     return turns;
    // }

    string coup::Player::get_last_oper() {
        return this->last_oper;
    }

}