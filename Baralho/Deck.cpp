#include <iostream>

#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#pragma once

#include <random>
using namespace std;


#include "Card.cpp"

/*
Classe que representa um deck de cartas!
*/
class Deck {

private:
  const int deckSize = 61;
  vector<Card>  deck;
  vector<Card>::iterator it;
  int cardsInDeck = 0;

public:
  Deck(): deck(deckSize), it(deck.begin()) {

  }

/*
Iniciando um deck de cartas.
*/
  void starting() {
    it = deck.insert(it, Card(-2, "null", " "));
    pullCard();

  }
/*
Adicionando uma carta no deck.
*/
  void addCard(Card card) {

    deck.insert(it, 1, card);

    cardsInDeck++;

  }
/*
Mostrando cartas de um deck.
*/
  void showDeck() {
    for(int i = 0; i < cardsInDeck; i++) {
      deck.at(i).toString();
    }

    cout << endl;


  }
/*
Puxando uma carta de um deck.
*/
  Card pullCard() {
    if(!isEmpty()) {
      Card card = deck[0];
      deck.erase(it);


        cardsInDeck--;


      return card;

    }
  }

/*
Embaralhar cartas de um deck.
*/
  void shuffleDeck () {
    int i,j;

    for (i = 0; i < cardsInDeck; i++) {

        do {
            j = rand()%52;
        } while (cardsInDeck < j);

        Card card = deck[i];
        deck[i] = deck[j];
        deck[j] = card;
    }
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
  Deck outDeck;
  deck.starting();
  deck.showDeck();
  outDeck.showDeck();
  outDeck.starting();




  Card card(1, "Azul", "+2");
  Card card2(5, "Verde", "+2");
  Card card3(7, "Amarela", "+2");
  Card card4(9, "Amarela", "+2");
  Card card5(5, "Amarela", "+2");

  deck.addCard(card);
  deck.addCard(card2);
  deck.addCard(card3);
  deck.addCard(card4);
  deck.addCard(card5);

  deck.shuffleDeck();
  cout << "Antes de tudo" << endl;;
  cout << "Sou o deck" << endl;
  deck.showDeck();
  cout << "Sou o outdeck" << endl;
  outDeck.showDeck();


  outDeck.addCard(deck.pullCard());
  outDeck.addCard(deck.pullCard());
  outDeck.addCard(deck.pullCard());
  outDeck.addCard(deck.pullCard());
  outDeck.addCard(deck.pullCard());


  cout << "Depois de adicionar no out" << endl;
  cout << "Sou o deck" << endl;
  deck.showDeck();
  cout << "Sou o outDeck" << endl;
  outDeck.showDeck();



  //deck.showDeck()
  if(deck.getCardsInDeck() == 0) {
    cout << "Cheguei aqui!!" << endl;
    Card upCard = outDeck.pullCard();


      deck.addCard(outDeck.pullCard());
      deck.addCard(outDeck.pullCard());
      deck.addCard(outDeck.pullCard());
      deck.addCard(outDeck.pullCard());




    outDeck.addCard(upCard);
    deck.shuffleDeck();
  }


    cout << "Resultado final:" << endl;
      cout << "Sou o deck" << endl;
    deck.showDeck();
      cout << "Sou o outdeck" << endl;
    outDeck.showDeck();

    return 1;


}*/
