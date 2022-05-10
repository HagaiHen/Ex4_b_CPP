#include "Game.hpp"
#include <vector>
#include <string>
#include <iostream>

namespace coup {

    std::vector<std::string> coup::Game::players() {
        vector<string> vec;
        for (size_t i = 0; i < this->list.size(); i++) {
            if (this->list[i] != "KILLED") {
                vec.push_back(this->list[i]);
            }
        }
        return vec;
    }
    std::string coup::Game::turn() {
        //cout << "hey" << endl;
        size_t tmp = this->curr_turn % this->list.size();
        // size_t tmp = (size_t) this->num_of_turns % this->list.size();
        // while (this->list[tmp] == "KILLED") {
        //     tmp = (tmp +1) % this->list.size();
        // }
        //cout << tmp << endl;
        return this->list[tmp];
    }

    void coup::Game::next_turn() {
        // cout << this->curr_turn << endl; 
        //cout << "TTT" << endl;
        this->curr_turn = (this->curr_turn+1)%this->list.size();
        //cout << "TTT" << endl;
        //cout << this->curr_turn << endl;
        while (this->list[this->curr_turn] == "KILLED") {
            //cout << "TTT" << endl;
            this->curr_turn = (this->curr_turn+1)%this->list.size();
        }
        //cout << this->curr_turn << endl;
        // cout << this->turn() << endl;
        // cout << this->list[tmp] << endl;
    }

    void coup::Game::addPlayer(string s) {
        this->list.push_back(s);
    }

    void coup::Game::back_to_game(size_t n, string s) {
        this->list[n] = s;
        cout << "revive " << n << endl;
    }

    void coup::Game::addPlayer_after(string s) {
        
        this->list.clear();
        vector<string> vec;
        for (size_t i = 0; i < this->list.size(); i++) {
            vec.push_back(this->list[i]);
        }
        vec.push_back(s);
        this->list = vec;
        
        //cout << this->list.size() << endl;
    }



    //TODO: fix players() for size.
    //TODO: block by contessa
    //TODO: kiiled by assian

    void coup::Game::remove_player(string s) {
        for (size_t i = 0; i < this->list.size(); i++) {
            if (this->list[i] == s){
                this->list[i] = "KILLED";
            }
        }
    }

    void coup::Game::inc() {
        this->num_of_turns++;
        //cout << this->num_of_turns << endl;
    } 

    string coup::Game::winner() {
        if (this->players().size() == 1 && this->num_of_turns > 0) {
            //cout << this->players()[0] << endl;
        } else {
            throw "Error";
        }
        return this->players()[0];
    }
}