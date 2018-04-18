#include <iostream>

class Vehicle {
	public:
	Vehicle(int a){
		std::cout<<"konstruktor vehicle, a: "<<a<<std::endl;
	}
	
};

class Engine {
public:
	void start() const {}
	void rev() const {}
	void stop() const {}
};

class Wheel {
public:
	void inflate(int psi) const {}
};

class Window {
public:
	void rollup() const {}
	void rolldown() const {}
};

class Door {
public:
Window window;
void open() const {}
void close() const {}
};

class Car : public Vehicle {
public:
Car();
Engine engine;
Wheel wheel[4];
Door left, right; // Dwoje drzwi
};

Car::Car():Vehicle(4)
{
	std::cout<<"konstruktor Car"<<std::endl;
}

int main() {
Car car;
car.left.window.rollup();
car.wheel[0].inflate(72);
}
