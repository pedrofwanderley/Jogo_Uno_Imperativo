#include <iostream>
using namespace std;

#include <string>

#include "../Baralho/Deck.cpp"

class Human: public Player {
public:
  Human(int id, string name):Player(id){
    setName(name);
  }

  void setName(string newName) {
    name = newName;
  }

  string getName() {
    return name;
  }
private:
  string name;

};
