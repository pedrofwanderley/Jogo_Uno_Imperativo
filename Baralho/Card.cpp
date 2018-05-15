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

  void setColour(string newColour) {
    colour = newColour;
  }

  void setNumber(int newNumber) {
    number = newNumber;
  }

  void toString() const {
    cout << "Card -> Number: " << (number-1) << " | Colour: " << colour << endl;
  }


protected:
  int number;
  string colour;
};
