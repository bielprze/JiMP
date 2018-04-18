#include <iostream>

//: C14:Combined.cpp 
// Inheritance & composition 
class A { 
  int i; 
public: 
  A(int ii) : i(ii) {std::cout<<"A konstruktor"<<std::endl;} 
  ~A() {} 
  void f() const {std::cout<<"A destruktor"<<std::endl;} 
}; 
class B { 
  int i; 
public: 
  B(int ii) : i(ii) {std::cout<<"B konstruktor"<<std::endl;}  
  ~B() {std::cout<<"B destruktor"<<std::endl;} 
  void f() const {} 
}; 
class C : public B { 
  A a; 
public: 
  C(int ii) : B(ii), a(ii) {std::cout<<"C konstruktor"<<std::endl;} 
  ~C() {std::cout<<"C destruktor"<<std::endl;} // Calls ~A() and ~B() 
  void f() const {  // Redefinition 
    a.f(); 
    B::f(); 
  } 
}; 

class D:public B{
public:
	C c;
	D():B(int i),A(int ii), c(int iii){
		std::cout<<"D konstruktor"<<std::endl;
	}
	~D(){
		std::cout<<"D destruktor"<<std::endl;
	}
};
int main() { 
  C c(47); 
} ///:~ 
