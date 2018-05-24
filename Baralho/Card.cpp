#include <iostream>
#include <string>
#pragma once
using namespace std;
/*
Classe que representa uma carta do jogo!
*/
class Card {

public:
  Card(int number, string colour, string effect) {
      setNumber(number);
      setColour(colour);
      setEffect(effect);
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

  void setEffect(string newEffect){
    effect = newEffect;
  }

  void toString() const {
    cout << "Card -> Number: " << number << " | Colour: " << colour << " | Effect: " << effect << endl;
  }


protected:
  int number;
  string colour;
  string effect;
};
