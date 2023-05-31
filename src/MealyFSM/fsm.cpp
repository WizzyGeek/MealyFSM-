#include"fsm.hpp"

template<typename Input, typename Output>
Output MealyFSM<Input, Output>::transition(const Input& inp) {
    MealyFSM::transition_state st {this->state, inp};
    MealyFSM::transition_state_end s = this->transitions.at(st);
    this->state = s.state;
    return s.out;
}

template<typename Input, typename Output>
void MealyFSM<Input, Output>::add_transition(unsigned int from, unsigned int to, Input inp, Output out) {
    MealyFSM::transition_state st {from, inp};
    MealyFSM::transition_state_end s {to, out};
    this->transitions[st] = s;
}

template class MealyFSM<char, bool>;