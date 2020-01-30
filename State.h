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
    State<T> *prev;

public:
    //Constructor.
    State(double cost, T state);
    //set the state.
    void setState(T _state);
    //return currrent node cost
    double getCost();
    //set the cost
    void setCost(double cost);
    //set the state (true or false)
    void setVisitState(bool visit);
    //get the visit state
    bool getVisit();
    //set the previous node
    void setPrev(State<T> * p);
    //return previous
    State <T> *getPrev();
    //return this.
    T getState();

    //override operators.
    bool operator==( State<T> &other) {
        return this->s == other.getState();
    }

    bool operator<(const State<T> &other) const {
        return this->s < other.getState();
    }

    bool operator!=( State<T> &other) {
        return this->s != other.getState();
    }
};
/**
 * set the state
 * @tparam T
 * @param p
 */
 template<typename T>
 void State<T>::setPrev(State<T> * p) {
     this->prev = p;
     setVisitState(true);
 }
/**
 * return state
 * @tparam T
 * @return state
 */
 template<typename T>
 T State<T>::getState() {
     return s;
 }
/**
 * return the visit state
 * @tparam T
 * @return visit state
 */
 template<typename T>
 bool State<T>::getVisit() {
     return is_visitedNode;
 }
/**
 * cost of state
 * @tparam T
 * @return cost
 */
 template<typename T>
 double State<T>::getCost() {
     return cost;
 }
/**
 * set the cost of the state
 * @tparam T
 * @param cost
 */
 template<typename T>
 void State<T>::setCost(double cost) {
     this->cost = cost;
 }
/**
 * set if visited or not.
 * @tparam T
 * @param visit
 */
 template<typename T>
 void State<T>::setVisitState(bool visit) {
     this->is_visitedNode = visit;
 }
/**
 * set the state
 * @tparam T
 * @param _state
 */
 template<typename T>
 void State<T>::setState(T _state) {
     this->s = _state;
 }
/**
 * Constructor.
 * @tparam T
 * @param cost
 * @param state
 */
 template<typename T>
 State<T>::State(double cost, T state) {
     setState(state);
     setPrev(nullptr);
     setCost(cost);
     setVisitState(false);
 }
/**
 * Set the previous state
 * @tparam T
 * @return
 */
 template<typename T>
 State<T> * State<T>::getPrev() {
     return prev;
 }

#endif //MILESTONE_2_STATE_H
