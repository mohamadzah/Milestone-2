 //
// Created by zahalka on 16/01/2020.
//

#ifndef MILESTONE_2_STATE_H
#define MILESTONE_2_STATE_H

template <typename T>
class State {
protected:
    double cost{};
    T s;
    bool is_visitedNode{};
    State<T> prev;

public:
    State(T state);
    void setState(T _state);
    double getCost();
    double setCost(double cost);
    void setVisitState(bool visit);
    bool getVisit();
    void setPrev(State<T> p);
    void getState();

    //override operators.
    bool operator==( State<T> &other) {
        return this->s == other.getState();
    }

    bool operator<(const State<T> &other) const {
        return this->s == other.getState();
    }
};

 template<typename T>
 void State<T>::setPrev(State<T> p) {
     this->prev = p;
     setVisitState(true);
 }

 template<typename T>
 void State<T>::getState() {
     return s;
 }

 template<typename T>
 bool State<T>::getVisit() {
     return is_visitedNode;
 }

 template<typename T>
 double State<T>::getCost() {
     return cost;
 }

 template<typename T>
 double State<T>::setCost(double cost) {
     return this->cost = cost;
 }

 template<typename T>
 void State<T>::setVisitState(bool visit) {
     this->is_visitedNode = visit;
 }

 template<typename T>
 void State<T>::setState(T _state) {
     this->s = _state;
 }

 template<typename T>
 State<T>::State(T state) {
     setState(state);
     setPrev(nullptr);
     setCost(0);
     setVisitState(false);
 }

#endif //MILESTONE_2_STATE_H
