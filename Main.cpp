#include <iostream>
#include <stdlib.h>
using namespace std;

#include "Baralho/Deck.cpp"
#include "Baralho/Card.cpp"
#include "Player/Player.cpp"
#include "Baralho/SpecialCard.cpp"
#include "Player/Human.cpp"
#include "Game/system.cpp"
/*
Método de distribuição de cartas para os players que vão participar do jogo.
*/
void distributeCards(Player &player, Deck &deck) {
  for(int p = 0; p < 7; p++) {
    Card card = deck.pullCard();
    player.addCard(card);

  }

}
/*
Método de construção do deck de cartas do jogo.
*/
void buildDeck(Deck &deck) {
  // Adicionando as cartas numericas 0-9
   for(int i = 0; i < 4; i++) {
     for(int j = 0; j < 10; j++) {

         if( i ==1){

             Card card1(j, "Azul", " ");
             deck.addCard(card1);

         }

         else if(i == 2) {
             Card card2(j, "Verde", "");
             deck.addCard(card2);

         }
           else if(i == 3) {
             Card card3(j, "Amarela", "");
             deck.addCard(card3);
           }
           else {
             Card card4(j, "Vermelha", "");
             deck.addCard(card4);
           }
         }

       }


   //Adicionando as cartas especiais com cores
   for(int k = 10; k < 13; k++) {
       if(k == 10){
         Card card5(k, "Azul", "+2");
         Card card6(k, "Verde", "+2");
         Card card7(k, "Amarela", "+2");
         Card card8(k, "Vermelha", "+2");
         deck.addCard(card5);
         deck.addCard(card6);
         deck.addCard(card7);
         deck.addCard(card8);

       } else if(k == 11) {
         Card card9(k, "Azul", "blocked");
         Card card10(k, "Verde", "blocked");
         Card card11(k, "Amarela", "blocked");
         Card card12(k, "Vermelha", "blocked");
         deck.addCard(card9);
         deck.addCard(card10);
         deck.addCard(card11);
         deck.addCard(card12);
       } else if(k == 12) {

         Card card13(k, "Azul", "reversed");
         Card card14(k, "Verde", "reversed");
         Card card15(k, "Amarela", "reversed");
         Card card16(k, "Vermelha", "reversed");
         deck.addCard(card13);
         deck.addCard(card14);
         deck.addCard(card15);
         deck.addCard(card16);
       } else {

       }
     }


   // Adicionando os coringas
   for(int l = 0; l < 4; l++) {

       Card card20(14,"Preta","+4");
       Card card25(13,"Preta","newColour");
       deck.addCard(card20);
       deck.addCard(card25);
    }


}

int main() {
  srand( time(NULL));
  Deck deck;
  Deck outDeck;
  System system1;

  deck.starting();
  outDeck.starting();

  Card card(8, "Amarela", "");
  outDeck.addCard(card);

  buildDeck(deck);

  deck.shuffleDeck();

  Human player(5, "Joao");
  Human player2(1, "coutz");
  Human player3(0, "tibes");
  Human player4(3, "lukinhas");

  int position = 1;
  bool reversed = false;
  Player players[5] = {player, player, player2, player3, player4};
  distributeCards(players[1], deck);
  distributeCards(players[2], deck);
  distributeCards(players[3], deck);
  distributeCards(players[4], deck);

  while(1){
    outDeck.showDeck();
    printf("PLAYER 1\n");
    players[1].showHand();
    printf("\n\n");
    printf("PLAYER 2\n");
    players[2].showHand();
    printf("\n\n");
    printf("PLAYER 3\n");
    players[3].showHand();
    printf("\n\n");
    printf("PLAYER 4\n");
    players[4].showHand();
    printf("\n\n");
    outDeck.showDeck();
    printf("\n\n");
    printf("JOGADOR %d PODE JOGAR:", position);
    if(system1.haveCard(players, outDeck.getDeck()[0], position)){
       system1.playCard(players, outDeck.getDeck()[0], deck, outDeck, position, reversed);
    }else{
       system1.pickAndPlay(players[position], deck, outDeck);
       system1.normalMoviment(position, reversed);
    }
       system("cls");
  }

  /*outDeck.showDeck();
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
    */


return 1;

}
