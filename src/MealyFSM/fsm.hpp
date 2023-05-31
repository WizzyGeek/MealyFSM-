#pragma once
#include<map>
#include<utility>

template<typename Input, typename Output>
class MealyFSM {
    public:
    using transition_state = std::pair<unsigned int, Input>;

    struct transition_state_end {
        unsigned int state;
        Output out;
    };

    std::map<transition_state, transition_state_end> transitions;
    unsigned int state = 0;

    MealyFSM() {};

    MealyFSM(const MealyFSM &fsm) {
        transitions = fsm.transitions;
    }

    MealyFSM(const MealyFSM &&fsm) {
        transitions = std::move(fsm.transitions);
    }

    virtual ~MealyFSM() {};

    void add_transition(unsigned int from, unsigned int to, Input inp, Output out);
    Output transition(const Input&);
};