#include <iostream>

#include "../Baralho/Deck.cpp"
#include "../structs.h"
#include "Player.cpp"
using namespace std;


int positionFour=0;
int positionTwo=0;
int positionBlocked=0;
int positionReversed=0;
int positionNormalCard=0;
int positionNewColour=0;

void zeringValues(){
    positionFour=0;
    positionTwo=0;
    positionBlocked=0;
    positionReversed=0;
    positionNormalCard=0;
    positionNewColour=0;
}

 int nextPlayer(int position, bool reversed){
        if(reversed){
            if(position == 1)
                return 4;
            else
                return position-1;
        }else{
            if(position == 4)
                return 1;
            else
                return position+1;
        }
}


/*
Método que checa se o player tem possibilidade de jogar na rodada.
*/
    bool checkCard(Card cardHand, Card upCard){
        if(cardHand.colour.compare(upCard.colour)==0){
            return true;
        }
        if(cardHand.number==upCard.number){
            return true;
        }
        if(cardHand.colour.compare("Preta")==0||cardHand.effect.compare("newColour")==0 || cardHand.effect.compare("+4")==0){
            return true;
        }
            return false;
    }

    /*
    * O método retorna a posição de uma carta para o bot jogar, em uma situação intermediária do jogo.
    * Uma situação intermediária é quando o inimigo tem 3 cartas na mão.
    */
    int midGame(){
        if(positionTwo != 0) {
            return positionTwo;
        } else if(positionBlocked != 0) {
            return positionBlocked;
        } else if(positionReversed != 0) {
            return positionReversed;
        } else if(positionNewColour != 0) {
          return positionNewColour;
        } else if(positionFour != 0) {
            return positionFour;
        } else {
            return positionNormalCard;
        }
    }

    /*
    * O método retorna a posição de uma carta para o bot jogar, em uma situação perigosa do jogo.
    * Uma situação perigosa é quando o inimigo tem no máximo 2 cartas na mão.
    */
    int dangerGame(){
        if(positionFour != 0) {
            return positionFour;
        } else if(positionNewColour != 0) {
            return positionNewColour;
        } else if(positionTwo != 0) {
            return positionTwo;
        } else if(positionBlocked != 0) {
            return positionBlocked;
        } else if(positionReversed != 0) {
            return positionReversed;
        } else {
            return positionNormalCard;
        }
    }

    /*
    * O método retorna a posição de uma carta para o bot jogar, em uma situação normal do jogo.
    * Uma situação normal é quando o inimigo tem no mínimo 4 cartas na mão.
    */
    int safeGame(){
        if(positionNormalCard != 0) {
            return positionNormalCard;
        } else if(positionReversed != 0) {
            return positionReversed;
        } else if(positionBlocked != 0) {
            return positionBlocked;
        } else if(positionTwo != 0) {
            return positionTwo;
        } else if(positionNewColour != 0) {
            return positionNewColour;
        } else {
            return positionFour;
        }
    }

/*
Método de escolha de cartas especiais pelo bot.
*/
    void chooseCards(Player* players, int position, bool reversed, Card upCard){
        Player myPlayer = players[position];

        for(int i=0; i<getNumberCards(myPlayer); i++){
            if(checkCard(myPlayer.hand.at(i), upCard)){

                if(myPlayer.hand.at(i).effect.compare("+4")==0)
                    positionFour=i+1;
                if(myPlayer.hand.at(i).effect.compare("+2")==0)
                    positionTwo=i+1;
                if(myPlayer.hand.at(i).effect.compare("reversed")==0)
                    positionReversed=i+1;
                if(myPlayer.hand.at(i).effect.compare("blocked")==0)
                    positionBlocked=i+1;
                if(myPlayer.hand.at(i).effect.compare("newColour")==0)
                    positionNewColour=i+1;
                if(myPlayer.hand.at(i).effect.compare("")==0)
                    positionNormalCard=i+1;
            }
        }
    }
    /*
    * O método procura qual cor se repete mais na mão do jogador.
    */
    int findMax(int blueCards, int greenCards, int yellowCards, int redCards) {
      int bestColour = 0;

      int colours[4] = {blueCards, greenCards, yellowCards, redCards};

      for(int i = 1; i < 4; i++) {
        if(colours[i] >= colours[bestColour]) {
          bestColour = i;
        }
      }

      return bestColour;
    }
/*
Método que procura e retorna as cartas azuis do deck do bot.
*/
    int findBlueCards(Player* players, int position) {
      int blueCards = 0;
      Player myPlayer = players[position];

      for(int i = 0; i < getNumberCards(myPlayer); i++) {
        if(myPlayer.hand.at(i).colour.compare("Azul") == 0 ) {
          blueCards++;
        }
      }

      return blueCards;
    }
/*
Método que procura e retorna as cartas amarelas do deck do bot.
*/
    int findYellowCards(Player* players, int position) {
      int yellowCards = 0;
      Player myPlayer = players[position];

      for(int i = 0; i < getNumberCards(myPlayer); i++) {
        if(myPlayer.hand.at(i).colour.compare("Amarela") == 0 ) {
          yellowCards++;
        }
      }

      return yellowCards;
    }
/*
Método que procura e retorna as cartas vermelhas no deck do bot.
*/
    int findRedCards(Player* players, int position) {
      int redCards = 0;
      Player myPlayer = players[position];

      for(int i = 0; i < getNumberCards(myPlayer); i++) {
        if(myPlayer.hand.at(i).colour.compare("Vermelha") == 0 ) {
          redCards++;
        }
      }

      return redCards;
    }
/*
Método que procura e retorna as cartas verdes no deck do bot.
*/
    int findGreenCards(Player* players, int position) {
      int greenCards = 0;
      Player myPlayer = players[position];

      for(int i = 0; i < getNumberCards(myPlayer); i++) {
        if(myPlayer.hand.at(i).colour.compare("Verde") == 0 ) {
          greenCards++;
        }
      }

      return greenCards;
    }


/*
Método que define o nível de dificuldade do bot.
*/
    int logistic(Player* players, int position, bool reversed, Card upCard){
        zeringValues();
        chooseCards(players, position, reversed, upCard);

        int nextOponent = nextPlayer(position, reversed);
        Player myPlayer = players[position];
        Player myOponent = players[nextOponent];

        if(getNumberCards(myOponent) >= 4){
            return safeGame();
        }else if(getNumberCards(myOponent) <= 2){
            return dangerGame();
        }else{
            return midGame();
        }
    }

/*
Método de escolha de melhor carta(em funçao da cor da carta) a ser usada pelo bot.
*/
    string chooseBestColour(Player* players, int position) {
      int blueCards = findBlueCards(players, position);
      int greenCards = findGreenCards(players, position);
      int yellowCards = findYellowCards(players, position);
      int redCards = findRedCards(players, position);

      Player myPlayer = players[position];

      int bestColour = findMax(blueCards, greenCards, yellowCards, redCards);

      if(bestColour == 0) {
        return "Azul";
      } else if(bestColour == 1) {
        return "Verde";
      } else if(bestColour == 2) {
        return "Amarela";
      } else if(bestColour == 3){
        return "Vermelha";
      }

    }






