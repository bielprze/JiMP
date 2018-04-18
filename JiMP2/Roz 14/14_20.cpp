#include <iostream>

class SpaceShip{
public:
	void fly();
};

class Shuttle : public SpaceShip{
public:
	void land();
};

int main(void)
{
	Shuttle sh;
	return 0;
}
