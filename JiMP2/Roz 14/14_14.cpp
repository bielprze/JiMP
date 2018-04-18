#include <iostream>
#include <string>

using namespace std;

class Traveler {
public:
	string wew_t;
	Traveler(string s){
		wew_t = s;
	}
	Traveler(const Traveler &obj)
	{
		wew_t = obj.wew_t;
	}
	Traveler & operator = (  Traveler & obj)
	{
    	wew_t = obj.wew_t;
    	return *this;
	}
		
};

class Pager {
public:
	string wew_p;
	Pager(string s){
		wew_p = s;
	}
	Pager(const Pager &obj)
	{
		wew_p = obj.wew_p;
	}
	Pager & operator = (Pager & obj)
	{
    	wew_p = obj.wew_p;
    	return *this;
	}
};

class BT:public Traveler{
public:
	Pager p(string s);
	BT();
	BT(string s):Traveler("s"){
	}
	BT(const BT &obj){
		p = obj.p;
	}
	BT & operator = (BT & obj)
	{
    	p = obj.p;
    	return *this;
	}
};

BT::BT():Traveler("s"){
	p.wew_p = "os";
}

int main(void){
	
	return 0;
}
