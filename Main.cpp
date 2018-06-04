#include <iostream>
#include <stdlib.h>
using namespace std;

#include "Baralho/Deck.cpp"
#include "Baralho/Card.cpp"
#include "Player/Player.cpp"
#include "Game/System.cpp"

/*
Método de distribuição de cartas para o player que vai participar do jogo.
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

      if(i == 1){
        Card card1(j, "Azul", "");
        deck.addCard(card1);
        deck.addCard(card1);
      }

      else if(i == 2) {
        Card card2(j, "Verde", "");
        deck.addCard(card2);
        deck.addCard(card2);
      }

      else if(i == 3) {
        Card card3(j, "Amarela", "");
        deck.addCard(card3);
        deck.addCard(card3);
      }

      else {
        Card card4(j, "Vermelha", "");
        deck.addCard(card4);
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

/*
 O metodo verifica se o jogo está em condições de acabar: Se não tiver mais cartas no deck, ou algum jogador tem 0 cartas na mão.
*/
int endGame(Player* players, Deck deck) {
  int winner = -1;

  if(deck.getCardsInDeck() == 0) {
    cout << "O numero de cartas no deck esgotou! O vencedor sera aquele que tiver menos cartas." << endl;

    winner = 1;

    for(int i = 2; i <= 4; i++) {
      if(players[i].getNumberCards() < players[winner].getNumberCards()) {
        winner = i;
      }
    }

  }

  for(int i = 1; i <= 4; i++) {
    if(players[i].getNumberCards() == 0) {
      winner = i;
    }
  }

  return winner;
}

void showMenu() {
  cout << endl;
  cout << "*---------------------------------------------*" << endl;
  cout << "|------ Seja bem-vindo(a) ao jogo UNO! -------|" << endl;
  cout << "|---------------------------------------------|" << endl;
  cout << "|----------- Escolha uma opção: --------------|" << endl;
  cout << "|---------------------------------------------|" << endl;
  cout << "|----------- 1) Começar o jogo ---------------|" << endl;
  cout << "|----------- 2) Ler regras -------------------|" << endl;
  cout << "|----------- 3) Sair -------------------------|" << endl;
  cout << "|---------------------------------------------|" << endl;
  cout << "*---------------------------------------------*" << endl;
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
  cout << endl;

}



void playGame() {
  srand( time(NULL));
  Deck deck;
  Deck outDeck;
  System system1;

  deck.starting();
  outDeck.starting();

  buildDeck(deck);
  deck.shuffleDeck();
  deck.shuffleDeck();

  Card upCard = deck.pullCard();

  while(upCard.getColour().compare("Preta") == 0) {
    deck.addCard(upCard);
    deck.shuffleDeck();
    upCard = deck.pullCard();

  }

  outDeck.addCard(upCard);

  Player player(5);
  Player player2(1);
  Player player3(0);
  Player player4(3);

  int position = 1;
  bool reversed = false;

  Player players[5] = {player, player, player2, player3, player4};

  distributeCards(players[1], deck);
  distributeCards(players[2], deck);
  distributeCards(players[3], deck);
  distributeCards(players[4], deck);

  int winner = -1;

  while(winner == -1){

    printf("PLAYER 1: %d cartas \n", players[1].getNumberCards());
    printf("PLAYER 2: %d cartas \n", players[2].getNumberCards());
    printf("PLAYER 3: %d cartas \n", players[3].getNumberCards());
    printf("PLAYER 4: %d cartas \n", players[4].getNumberCards());
    cout << endl;


    if(position == 1) {
      printf("PLAYER 1\n");
      players[1].showHand();
      cout << endl;
      cout << endl;
      outDeck.getDeck()[0].toString();
      printf("JOGADOR %d PODE JOGAR:", position);
      cout << endl;

    } else {
      cout << endl;
      outDeck.getDeck()[0].toString();
      printf("O BOT %d ACABA DE JOGAR! ", position);
      cout << endl;
    }


    if(system1.haveCard(players, outDeck.getDeck()[0], position)){
      system1.playCard(players, outDeck.getDeck()[0], deck, outDeck, position, reversed);

    }else{
      system1.pickAndPlay(players, position, deck, outDeck, reversed);
    }

    winner = endGame(players, deck);
  }

    printf("O jogador %d venceu!!!", winner);
    printf("\n\n");
}



int main() {

  int opr = 0;

  while(opr != 3) {
    showMenu();
    cout << "Opção: " << endl;
    scanf("%d", &opr);

    if(opr == 1) {
      cout << "Jogo iniciado!!" << endl;
      cout << endl;
      cout << "Você é o jogador 1!" << endl;
      cout << endl;
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
