#include "Game.hpp"
#include <vector>
#include <string>
#include <iostream>

namespace coup {

    std::vector<std::string> coup::Game::players() {
        return this->list;
    }
    std::string coup::Game::turn() {
        //cout << "hey" << endl;
        size_t tmp = (size_t)this->num_of_turns % this->list.size();
        //cout << tmp << endl;
        return this->list[tmp];
    }

    void coup::Game::addPlayer(string s) {
        this->list.push_back(s);
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



    

    void coup::Game::remove_player(string s) {
        for (size_t i = 0; i < this->list.size(); i++) {
            if (this->list[i] == s){
                int j = i;
                this->list.erase(this->list.begin() + j);
            }
        }
    }

    void coup::Game::inc() {
        this->num_of_turns++;
        //cout << this->num_of_turns << endl;
    } 

    string coup::Game::winner() {
        if (this->list.size() == 1) {
            cout << this->list[0] << endl;
        } else {
            throw "Error";
        }
        return this->list[0];
    }
}