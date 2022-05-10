#pragma once
#include "Game.hpp"
#include <string>

using namespace std;
//using namespace coup;

namespace coup {

    class Player {

        protected:
            int money;
            string name;
            Game * game;
            string last_oper;
            Player * steal_from;
            
        public:
            size_t id;
            Player * couped;
            void income();
            int coins() const;
            void foreign_aid();
            virtual string role() const = 0;
            virtual void coup(Player &p); 
            int num_of_turns();
            string get_last_oper();
            void dec() { this->money--;};
            void inc() { this->money++;};
            string get_name() {return this->name;};
            Player (Game &g, const string &s);
            Player * get_steal_from() {return this->steal_from; };
    };
    
}