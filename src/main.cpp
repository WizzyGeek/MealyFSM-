#include<iostream>
#include"MealyFSM/fsm.hpp"

extern template class MealyFSM<char, bool>; // Wont compile without this

int main() {
    MealyFSM<char, bool> fsm;
    fsm.add_transition(0, 1, 'A', false);
    fsm.add_transition(0, 0, 'B', false);
    fsm.add_transition(1, 1, 'A', false);
    fsm.add_transition(1, 0, 'B', true);

    char c = 0;

    while(std::cin >> c) {
        std::cout << fsm.transition(c);
    }
    return 0;
}