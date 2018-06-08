#include <vector>
#include <string>
#include <iostream>
#pragma once

using namespace std;

typedef struct{
    int number;
    string colour;
    string effect;
}Card;

typedef struct{
    vector<Card> hand;
    int id;
}Player;



typedef struct{
    int sizeDeck;
    vector<Card> myDeck;
    vector<Card>::iterator it;
    int cardsInDeck;
}Deck;

