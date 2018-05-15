#include <iostream>
using namespace std;

#include "Baralho/Deck.cpp"
#include "Baralho/Card.cpp"
#include "Player/Player.cpp"


int main() {
  Deck deck;
  deck.starting();


 // Adicionando as cartas numericas 0-9
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 10; j++) {

        if( i ==1){

            Card card1(j+1, "Azul");
            deck.addCard(card1);

        }

        else if(i == 2) {
            Card card2(j+1, "Verde");
            deck.addCard(card2);

        }
          else if(i == 3) {
            Card card3(j+1, "Amarela");
            deck.addCard(card3);
          }
          else {
            Card card4(j+1, "Vermelha");
            deck.addCard(card4);
          }
        }

      }



  //Adicionando as cartas especiais com cores
  /*for(int k = 10; k < 14; k++) {
    switch(k) {
      case 10:
        SpecialCard card5(10, "Azul", "+2");
        SpecialCard card6(11, "Azul", "block");
        SpecialCard card7(12, "Azul", "revert");
        deck.addCard(card5);
        deck.addCard(card6);
        deck.add(card7);
        break;
      case 11:
        SpecialCard card8(10, "Amarela", "+2");
        SpecialCard card9(11, "Amarela", "block");
        SpecialCard card10(12, "Amarela", "revert");
        deck.addCard(card8);
        deck.addCard(card9);
        deck.add(card10);
        break;
      case 12:
        SpecialCard card11(10, "Verde", "+2");
        SpecialCard card12(11, "Verde", "block");
        SpecialCard card13(12, "Verde", "revert");
        deck.addCard(card11);
        deck.addCard(card12);
        deck.add(card13);
        break;
      case 13:
        SpecialCard card14(10, "Vermela", "+2");
        SpecialCard card15(11, "Vermelha", "block");
        SpecialCard card16(12, "Vermelha", "revert");
        deck.addCard(card14);
        deck.addCard(card15);
        deck.add(card16);
        break;
    }
  }

  // Adicionando os coringas
  *for(int l = 0; l < 8; l++) {
    if(l%2 == 0) {
      SpecialCard card20(20, "Preta", "+4");
      deck.addCard(card20);
    } else {
      SpecialCard card2(15, "Preta", "newColour");
      deck.addCard(card2);
    }
  } */
  deck.shuffle();
  Player player(5);

// distribui carta
  for(int p = 0; p < 7; p++) {
    Card card = deck.pullCard();

    if(card.getNumber() != 0) {
        player.addCard(card);
    } else {
      p--;
    }

  }

  deck.showDeck();
  cout << endl;
  player.showHand();
return 1;

}
