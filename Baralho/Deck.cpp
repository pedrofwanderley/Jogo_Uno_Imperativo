#include <iostream>

#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;


#include "Card.cpp"


class Deck {

private:
  const int deckSize = 61;
  vector<Card>  deck;
  vector<Card>::iterator it;
  int cardsInDeck = 0;

public:
  Deck(): deck(deckSize), it(deck.begin()) {

  }


  void starting() {
    it = deck.insert(it, Card());
  }

  void addCard(Card card) {

    deck.insert(it, 1, card);

    cardsInDeck++;

  }

  void showDeck() {
    for(int i = 0; i < cardsInDeck; i++) {
      deck.at(i).toString();
    }

    cout << endl;


  }

  Card pullCard() {


      Card card = deck[0];
      deck.erase(it);

      if(!isEmpty()) {
        cardsInDeck--;
      }

      return card;


  }



  void shuffle() {
    random_shuffle(deck.begin(), deck.end());

  }

  bool isEmpty() {
    return cardsInDeck == 0;
  }

  int getCardsInDeck() {
    return cardsInDeck;
  }

  vector<Card> getDeck() {
    return deck;
  }

};

/*int main() {
  srand( time(NULL));
  Deck deck;
  deck.starting();
  cout << deck.isEmpty();
  Card card(1, "Azul");
  deck.addCard(card);

  cout << deck.isEmpty();

  deck.pullCard();
  cout << deck.isEmpty();

    deck.pullCard();
    Card card2(5, "Verde");
    card2.toString();
    deck.addCard(card2);
    deck.addCard(card);

    cout << deck.isEmpty();
    deck.pullCard();
    deck.pullCard();
    cout << deck.isEmpty();

    cout << "End here";

    deck.addCard(card);
    deck.addCard(card);
    deck.addCard(card2);


    deck.showDeck();



  //deck.showDeck()







}*/
