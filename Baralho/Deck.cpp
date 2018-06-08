#include <iostream>

#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#pragma once

#include <random>
using namespace std;

#include "../structs.h"
#include "Card.cpp"


bool isEmpty(Deck &deck) {
    return deck.cardsInDeck == 0;
}
/*
Puxando uma carta de um deck.
*/
  Card pullCard(Deck &deck) {
    if(!isEmpty(deck)) {
      Card card = deck.myDeck[0];
      deck.it = deck.myDeck.erase(deck.it);
      deck.cardsInDeck--;
      return card;
    }
  }


/*
Iniciando um deck de cartas.
*/
  void starting(Deck &deck) {
    Card novoCard;
    novoCard.colour = "";
    novoCard.effect = "";
    novoCard.number = -2;
    deck.it = deck.myDeck.insert(deck.it, novoCard);
    deck.cardsInDeck++;
    pullCard(deck);
  }
/*
Adicionando uma carta no deck.
*/
  void addCard(Card &card, Deck &deck) {
    deck.it = deck.myDeck.insert(deck.it, 1, card);
    deck.cardsInDeck++;
  }
/*
Mostrando cartas de um deck.
*/
  void showDeck(Deck &deck) {
    for(int i = 0; i < deck.cardsInDeck; i++) {
      toString(&deck.myDeck.at(i));
    }
    cout << endl;
  }


/*
Embaralhar cartas de um deck.
*/
  void shuffleDeck (Deck &deck) {
    int i,j;
    for (i = 1; i < deck.cardsInDeck; i++) {
        j = rand() % i;
        Card card = deck.myDeck[i];
        deck.myDeck[i] = deck.myDeck[j];
        deck.myDeck[j] = card;
    }

  }


  int getCardsInDeck(Deck &deck) {
    return deck.cardsInDeck;
  }

  vector<Card> getDeck(Deck &deck) {
    return deck.myDeck;
  }

