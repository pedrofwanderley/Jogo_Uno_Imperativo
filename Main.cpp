#include <iostream>
using namespace std;

#include "Baralho/Deck.cpp"
#include "Baralho/Card.cpp"
#include "Player/Player.cpp"
#include "Baralho/SpecialCard.cpp"
#include "Player/Human.cpp"
#include "Game/System.cpp"

void distributeCards(Player &player, Deck &deck) {
  for(int p = 0; p < 7; p++) {
    Card card = deck.pullCard();
    player.addCard(card);

  }

}

void buildDeck(Deck &deck) {
  // Adicionando as cartas numericas 0-9
   for(int i = 0; i < 4; i++) {
     for(int j = 0; j < 10; j++) {

         if( i ==1){

             Card card1(j, "Azul");
             deck.addCard(card1);

         }

         else if(i == 2) {
             Card card2(j, "Verde");
             deck.addCard(card2);

         }
           else if(i == 3) {
             Card card3(j, "Amarela");
             deck.addCard(card3);
           }
           else {
             Card card4(j, "Vermelha");
             deck.addCard(card4);
           }
         }

       }


   //Adicionando as cartas especiais com cores
   for(int k = 10; k < 13; k++) {
       if(k == 10){
         SpecialCard card5(k, "Azul", "+2");
         SpecialCard card6(k, "Verde", "+2");
         SpecialCard card7(k, "Amarela", "+2");
         SpecialCard card8(k, "Vermelha", "+2");
         deck.addCard(card5);
         deck.addCard(card6);
         deck.addCard(card7);
         deck.addCard(card8);

       } else if(k == 11) {
         SpecialCard card9(k, "Azul", "block");
         SpecialCard card10(k, "Verde", "block");
         SpecialCard card11(k, "Amarela", "block");
         SpecialCard card12(k, "Vermelha", "block");
         deck.addCard(card9);
         deck.addCard(card10);
         deck.addCard(card11);
         deck.addCard(card12);
       } else if(k == 12) {

         SpecialCard card13(k, "Azul", "revert");
         SpecialCard card14(k, "Verde", "revert");
         SpecialCard card15(k, "Amarela", "revert");
         SpecialCard card16(k, "Vermelha", "revert");
         deck.addCard(card13);
         deck.addCard(card14);
         deck.addCard(card15);
         deck.addCard(card16);
       } else {

       }
     }


   // Adicionando os coringas
   for(int l = 0; l < 4; l++) {

       SpecialCard card20(14,"Preta","+4");
       SpecialCard card25(13,"Preta","newColour");
       deck.addCard(card20);
       deck.addCard(card25);
    }


}

int main() {
  srand( time(NULL));
  Deck deck;
  Deck outDeck;
  System system;

  deck.starting();
  outDeck.starting();

  Card card(8, "Amarela");
  outDeck.addCard(card);

  buildDeck(deck);

  deck.shuffleDeck();

  Human player(5, "Joao");
  distributeCards(player, deck);
  for(int i=1; i<6; i++)
    player.dropCard(i);
  deck.showDeck();
  cout << endl;
  player.showHand();
  cout << endl;
  // Definir qual vai ser o primeiro e o ultimo dos decks por enquanto \/
  if(system.haveCard(player, deck.getDeck()[deck.getCardsInDeck()-1])){
    system.playCard(player, deck.getDeck()[deck.getCardsInDeck()-1], deck, outDeck);
  }else{
    system.pickAndPlay(player, deck, outDeck);
  }
  cout << "OUTDECKKKK" << endl;
  outDeck.showDeck();
  cout << endl;
  player.showHand();



return 1;

}
