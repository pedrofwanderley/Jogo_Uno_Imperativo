#include <vector>
#include <string>
#include <iostream>
using namespace std;

struct Card{
    int number;
    string colour;
    string effect;
}Card;

struct Player{
    vector<struct Card> hand;
    int id;
}Player;



struct Deck{
    int sizeDeck;
    vector<struct Card> myDeck;
    vector<struct Card>::iterator it;
    int cardsInDeck;
};
