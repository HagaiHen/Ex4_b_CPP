#pragma once
#include <string>
#include <vector>
// #include "Player.hpp"
using namespace std;

namespace coup {

    class Game {

        private:
            vector<string> list;
            int num_of_turns;
            void * last_coup;

        public:
            vector<string> players();
            string turn();
            void addPlayer(string s);
            void addPlayer_after(string s);
            void inc();
            void remove_player(string name);
            void * get_last_coup() {return this->last_coup;};
            void set_last_coup(void* &p) {this->last_coup = &p;};
            string winner ();
        
    };
    
}