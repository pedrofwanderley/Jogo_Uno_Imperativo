#include <iostream>
#include <string>
#pragma once
#include "../structs.h"
using namespace std;

void toString(Card *card){
    if(card->effect.compare("") == 0)
        cout << "Card -> Number: " << card->number <<" | Colour: " << card->colour << " | Effect: " << card->effect << endl;
    else
        cout << "Card -> Number: " << card->number << " | Colour: " << card->colour << endl;
}
