#include <iostream>
#include <string>

using namespace std;

#include "Card.cpp"

class SpecialCard: public Card {
public:
  SpecialCard(int number, string colour, string effect):Card(number, colour) {
    setEffect(effect);
  }

  void setEffect(string newEffect) {
    effect = newEffect;
  }

  string getEffect() {
    return effect;
  }

  void toString() const {
    cout << "Card -> Number: " << number << " | Colour: " << colour << " | Effect: " << effect << endl;
  }

private:
  string effect;
};