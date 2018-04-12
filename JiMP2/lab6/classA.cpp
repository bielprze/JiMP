#include <iostream>

class A {

	static unsigned int no;
	public:
		static A &getInstance()
		{
			if(!instance) instance = new A(); 
            return *instance;
		}
		~A(){--no;std::cout<<no<<std::endl;}
	private:
		
		static A* instance;
		A(){no_in();}
		static void no_in(){ ++no;std::cout<<no<<std::endl;}
		A(const A &a){ no_in();}

		
};
	unsigned int A::no=0;
	A* A::instance=0;

int main(int argc, char* argv[])
{
	
	A::getInstance();



	return 0;
}
