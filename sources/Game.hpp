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
            //Player * last_coup;
            size_t curr_turn = 0;
            

        public:
            size_t id = 0;
            vector<string> players();
            string turn();
            void addPlayer(string s);
            void addPlayer_after(string s);
            void inc();
            void remove_player(string name);
            //Player * get_last_coup() {return this->last_coup;};
            //void set_last_coup(Player * p) {this->last_coup = p;};
            string winner ();
            void next_turn ();
            void back_to_game(size_t n, string s);
            int get_num_of_turns() {return this->num_of_turns; };
        
    };
    
}