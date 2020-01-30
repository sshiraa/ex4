#pragma once
typedef enum { NOT = -1, UP, DOWN, LEFT, RIGHT } Direction;
using namespace std;
template <class T>
class State
{
private:
	T ob;
	double cost;
	State<T>* cameFrom;
	Direction direction;
public:
	//constructor
	State<T>();
	State(T object, double cost, State<T>* cameFrom, Direction direction) {
		this->ob = object;
		this->cost = cost;
		this->cameFrom = cameFrom;
		this->direction = direction;
	}
	//getters:
	State<T>* getCameFrom() {
		return this->cameFrom;;
	}
	T getObject() {
		return this->ob;
	}
	double getCost() {
		return this->cost;
	}
	Direction getDirection() {
		return this->direction;
	}
	//setters:
	void setCost(double newCost) {
		this->cost = newCost;
	}
	void setCameFrom(State<T>* currentCameFrom) {
		this->cameFrom = currentCameFrom;
	}
	void setDirection(char* newDirection) {
		this->direction = newDirection;
	}
};
