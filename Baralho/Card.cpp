#include <iostream>
#include <string>
#pragma once
using namespace std;

class Card {

public:
  Card(int number, string colour) {
      setNumber(number);
      setColour(colour);
  }

  Card() {

  }

  int getNumber() {
    return number;
  }

  string getColour() {
    return colour;
  }

  string getEffect(){
    return effect;
  }

  void setColour(string newColour) {
    colour = newColour;
  }

  void setNumber(int newNumber) {
    number = newNumber;
  }

  void toString() const {
    cout << "Card -> Number: " << number << " | Colour: " << colour << endl;
  }


protected:
  int number;
  string colour;
  string effect;
};
