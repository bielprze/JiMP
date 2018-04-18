//: C14:Instrument.cpp 
// Inheritance & upcasting 
#include <iostream>
enum note { middleC, Csharp, Cflat }; // Etc. 

class Instrument { 
public: 
  virtual void play(note) const {std::cout<<"adsasd"<<std::endl;} 
};

// Wind objects are Instruments 
// because they have the same interface: 
class Wind : public Instrument {
public:
	void play(note) const {std::cout<<"inny komuniakt"<<std::endl;}
}; 

void tune(Instrument& i) { 
  // ... 
  i.play(middleC); 
}
int main() { 
  Wind flute; 
  tune(flute); // Upcasting 
} ///:~ 
