#include <vector>

struct Player{
    vector<Card> hand;
    int id;
}

struct Card{
    int number;
    string colour;
    string effect;
}

struct Deck{
    int sizeDeck;
    vector<Card> myDeck;
    vector<Card>::iterator it;
    int cardsInDeck;
}
