#pragma once
typedef enum { NOT = -1, UP, DOWN, LEFT, RIGHT } Direction;

template <class T>
class State {
private:
	T current;
	double cost;
	State<T> *cameFrom;
	Direction direction;

public:
	State() { };
	//maybe changing the constructor to not-having father init, and using the set where needed
	State(T current, double cost, State<T> *father, Direction direction) : current(current), cost(cost),
		cameFrom(father), direction(direction) {};

	void setCost(double newCost) { cost = newCost; }

	void setCameFrom(State<T> *newVal) { cameFrom = newVal; }

	double getCost() { return cost; }

	T getObject() { return current; }

	State<T> *getCameFrom() { return cameFrom; }

	Direction getDirection() { return direction; }

	//overloading the operator instead of creating function called "Equal"
	bool operator==(State<T> another) { return (getObject() == another.getObject()); }
};

