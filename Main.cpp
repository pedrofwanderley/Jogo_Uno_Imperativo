#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
using namespace std;

#include "Baralho/Deck.cpp"
#include "Baralho/Card.cpp"
#include "Player/Player.cpp"
#include "Game/System.cpp"
#include "structs.h"

/*
Método de distribuição de cartas para o player que vai participar do jogo.
*/

void distributeCards(Player &player, Deck &deck) {
  for(int p = 0; p < 7; p++) {
    Card card = pullCard(deck);
    addCard(card, player);

  }

}
/*
Método de construção do deck de cartas do jogo.
*/
void buildDeck(Deck &deck) {
  // Adicionando as cartas numericas 0-9
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 10; j++) {

      if(i == 1){
        Card card1;
        card1.number = j;
        card1.colour ="Azul";
        card1.effect = "";
        addCard(card1, deck);
        addCard(card1, deck);
      }

      else if(i == 2) {
        Card card2;
        card2.number = j;
        card2.colour ="Verde";
        card2.effect = "";
        addCard(card2, deck);
        addCard(card2, deck);
      }

      else if(i == 3) {
        Card card3;
        card3.number = j;
        card3.colour ="Amarela";
        card3.effect = "";
        addCard(card3, deck);
        addCard(card3, deck);
      }

      else {
        Card card4;
        card4.number = j;
        card4.colour ="Vermelha";
        card4.effect = "";
        addCard(card4, deck);
        addCard(card4, deck);
      }
    }
  }

   //Adicionando as cartas especiais com cores
   for(int k = 10; k < 13; k++) {

       if(k == 10){
         Card card5;
         card5.colour = "Azul";
         card5.effect = "+2";
         card5.number = k;
         Card card6;
         card6.colour = "Amarela";
         card6.effect = "+2";
         card6.number = k;
         Card card7;
         card7.colour = "Vermelha";
         card7.effect = "+2";
         card7.number = k;
         Card card8;
         card8.colour = "Verde";
         card8.effect = "+2";
         card8.number = k;

         addCard(card5, deck);
         addCard(card6, deck);
         addCard(card7, deck);
         addCard(card8, deck);

       } else if(k == 11) {
         Card card9;
         card9.colour = "Azul";
         card9.effect = "blocked";
         card9.number = k;
         Card card10;
         card10.colour = "Amarela";
         card10.effect = "blocked";
         card10.number = k;
         Card card11;
         card11.colour = "Vermelha";
         card11.effect = "blocked";
         card11.number = k;
         Card card12;
         card12.colour = "Verde";
         card12.effect = "blocked";
         card12.number = k;

         addCard(card9, deck);
         addCard(card10, deck);
         addCard(card11, deck);
         addCard(card12, deck);

       } else if(k == 12) {

         Card card13;
         card13.colour = "Azul";
         card13.effect = "reversed";
         card13.number = k;
         Card card14;
         card14.colour = "Verde";
         card14.effect = "reversed";
         card14.number = k;
         Card card15;
         card15.colour = "Amarela";
         card15.effect = "reversed";
         card15.number = k;
         Card card16;
         card16.colour = "Vermelha";
         card16.effect = "reversed";
         card16.number = k;
         addCard(card13, deck);
         addCard(card14, deck);
         addCard(card15, deck);
         addCard(card16, deck);
       }
     }


   // Adicionando os coringas
   for(int l = 0; l < 4; l++) {
       Card card20;
       card20.colour = "Preta";
       card20.effect = "+4";
       card20.number = 12;
       Card card25;
       card25.colour = "Preta";
       card25.effect = "newColour";
       card25.number = 12;
       addCard(card20, deck);
       addCard(card25, deck);
    }


}

/*
 O metodo verifica se o jogo está em condições de acabar: Se não tiver mais cartas no deck, ou algum jogador tem 0 cartas na mão.
*/
int endGame(Player* players, Deck deck) {
  int winner = -1;

  if(getCardsInDeck(deck) == 0) {
    cout << "O numero de cartas no deck esgotou! O vencedor sera aquele que tiver menos cartas." << endl;

    winner = 1;

    for(int i = 2; i <= 4; i++) {
      if(getNumberCards(players[i]) < getNumberCards(players[winner])) {
        winner = i;
      }
    }

  }

  for(int i = 1; i <= 4; i++) {
    if(getNumberCards(players[i]) == 0) {
      winner = i;
    }
  }

  return winner;
}
void testMenu(){
 system("clear");
 printf("                      UUUUUUUU     UUUUUUUUNNNNNNNN        NNNNNNNN     OOOOOOOOO\n");
 printf("                      U::::::U     U::::::UN:::::::N       N::::::N   OO:::::::::OO\n");
 printf("                      U::::::U     U::::::UN::::::::N      N::::::N OO:::::::::::::OO\n");
 printf("                      UU:::::U     U:::::UUN:::::::::N     N::::::NO:::::::OOO:::::::O\n");
 printf("                       U:::::U     U:::::U N::::::::::N    N::::::NO::::::O   O::::::O\n");
 printf("                       U:::::D     D:::::U N:::::::::::N   N::::::NO:::::O     O:::::O\n");
 printf("                       U:::::D     D:::::U N:::::::N::::N  N::::::NO:::::O     O:::::O\n");
 printf("                       U:::::D     D:::::U N::::::N N::::N N::::::NO:::::O     O:::::O\n");
 printf("                       U:::::D     D:::::U N::::::N  N::::N:::::::NO:::::O     O:::::O\n");
 printf("                       U:::::D     D:::::U N::::::N   N:::::::::::NO:::::O     O:::::O\n");
 printf("                       U:::::D     D:::::U N::::::N    N::::::::::NO:::::O     O:::::O\n");
 printf("                       U::::::U   U::::::U N::::::N     N:::::::::NO::::::O   O::::::O\n");
 printf("                       U:::::::UUU:::::::U N::::::N      N::::::::NO:::::::OOO:::::::O\n");
 printf("                       UU:::::::::::::UU  N::::::N       N:::::::N OO:::::::::::::OO\n");
 printf("                        UU:::::::::UU    N::::::N        N::::::N   OO:::::::::OO\n");
 printf("                          UUUUUUUUU      NNNNNNNN         NNNNNNN     OOOOOOOOO\n");

}
void showMenu() {
  cout << endl;
  cout << "\t\t\t\t*---------------------------------------------*" << endl;
  cout << "\t\t\t\t|------ Seja bem-vindo(a) ao jogo UNO! -------|" << endl;
  cout << "\t\t\t\t|--------Derrote os ministros do STF ---------|" << endl;
  cout << "\t\t\t\t|---------  e salve o Brasil  ----------------|" << endl;
  cout << "\t\t\t\t|---------------------------------------------|" << endl;
  cout << "\t\t\t\t|----------- Escolha uma opção: --------------|" << endl;
  cout << "\t\t\t\t|---------------------------------------------|" << endl;
  cout << "\t\t\t\t|---------------------------------------------|" << endl;
  cout << "\t\t\t\t|----------- 1) Começar o jogo ---------------|" << endl;
  cout << "\t\t\t\t|----------- 2) Ler regras -------------------|" << endl;
  cout << "\t\t\t\t|----------- 3) Sair -------------------------|" << endl;
  cout << "\t\t\t\t|---------------------------------------------|" << endl;
  cout << "\t\t\t\t*---------------------------------------------*" << endl;
  cout << endl;
}

void showRules() {
    cout << endl;
    cout << "REGRAS DO JOGO!" << endl;
    cout << "1) O jogo é 1x3, ou seja, um jogador contra 3 bots inteligentes;" << endl;
    cout << "2) São distribuidas 7 cartas aleatórias para cada jogador;" << endl;
    cout << "3) Cada jogador só pode jogar 1 carta por vez;" << endl;
    cout << "4) Caso o jogador não tenha uma carta válida para a jogada, uma nova carta será automaticamente puxada do deck e jogada, caso seja válida;" << endl;
    cout << "5) O jogo acaba quando não houver mais cartas no deck ou quando algum jogador zerar o número de cartas na mão;" << endl;
    cout << "6) Se não houver mais cartas no deck, ganha o jogador que tiver menos cartas!" << endl;
    cout << endl << endl << " ---  Aperte qualquer tecla para voltar ---" << endl;
    getchar();
    getchar();
    cout << endl;

}

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

void playGame(){
  srand(time(NULL));

  Deck deck;
  deck.it = deck.myDeck.begin();
  deck.cardsInDeck = 0;

  Deck outDeck;
  outDeck.it = outDeck.myDeck.begin();
  outDeck.cardsInDeck = 0;

  starting(deck);
  starting(outDeck);

  buildDeck(deck);


  shuffleDeck(deck);
  shuffleDeck(deck);

  Card upCard = pullCard(deck);


  while(upCard.colour.compare("Preta") == 0) {
    addCard(upCard, deck);
    shuffleDeck(deck);
    upCard = pullCard(deck);
  }


  addCard(upCard, outDeck);

  Player player;
  Player player2;
  Player player3;
  Player player4;

  int position = 1;
  bool reversed = false;

  Player players[5] = {player, player, player2, player3, player4};

  distributeCards(players[1], deck);
  distributeCards(players[2], deck);
  distributeCards(players[3], deck);
  distributeCards(players[4], deck);

  int winner = -1;

  while(winner == -1){

    printf("PLAYER: %d cartas \n", getNumberCards(players[1]));
    printf("BOT DIAS TOFFOLI: %d cartas \n", getNumberCards(players[2]));
    printf("BOT CARMEN LUCIA: %d cartas \n", getNumberCards(players[3]));
    printf("BOT GILMAR MENDES: %d cartas \n", getNumberCards(players[4]));
    cout << endl;


    if(position == 1) {
      printf(" -- SUA MAO -- \n\n");
      showHand(players[1]);
      printf("\n-------------- \n");
      cout << endl;
      cout << endl;
      toString(&getDeck(outDeck)[0]);
      cout << endl;
      printf("VOCE PODE JOGAR:");
      cout << endl;

    } else {
      cout << endl;
      toString(&(getDeck(outDeck)[0]));
      if(position == 2)
            printf("O BOT DIAS TOFFOLI ACABA DE JOGAR!");
      if(position == 3)
            printf("O BOT CARMEN LUCIA ACABA DE JOGAR!");
      if(position == 4)
            printf("O BOT GILMAR MENDES ACABA DE JOGAR!");
      cout << endl;
    }


    if(haveCard(players, getDeck(outDeck)[0], position)){
      playCard(players, getDeck(outDeck)[0], deck, outDeck, position, reversed);
    }else{
      pickAndPlay(players, position, deck, outDeck, reversed);
    }
    winner = endGame(players, deck);
    delay(1000000);
    system("clear");
  }
    printf("O jogador %d venceu!!!", winner);
    printf("\n\n");
}



int main() {

  int opr = 0;

  while(opr != 3) {
    testMenu();
    showMenu();
    cout << "Opção: " << endl;
    scanf("%d", &opr);
    system("clear");
    if(opr == 1) {
      playGame();

    } else if(opr == 2) {
      showRules();

    } else if(opr == 3) {
      cout << "Tchau!" << endl;
      break;

    } else {
      cout << "Tente uma opção válida!" << endl;
    }

  }

  return 1;

}
