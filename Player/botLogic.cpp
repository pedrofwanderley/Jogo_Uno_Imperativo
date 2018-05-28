#include <iostream>

#include "../Baralho/Deck.cpp"
#include "Player.cpp"
using namespace std;

class botLogic{

public:
    botLogic(){};

    int logistic(Player* players, int position, bool reversed, Card upCard){
        zeringValues();
        chooseCards(players, position, reversed, upCard);

        int nextOponent = nextPlayer(position, reversed);
        Player myPlayer = players[position];
        Player myOponent = players[nextOponent];

        if(myOponent.getNumberCards() >= 4){
            return safeGame();
        }else if(myOponent.getNumberCards() <= 2){
            return dangerGame();
        }else{
            return midGame();
        }
    }

    void zeringValues(){
         positionFour=0;
         positionTwo=0;
         positionBlocked=0;
         positionReversed=0;
         positionNormalCard=0;
         positionNewColour=0;
    }

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

    int findBlueCards(Player* players, int position) {
      int blueCards = 0;
      Player myPlayer = players[position];

      for(int i = 0; i < myPlayer.getNumberCards(); i++) {
        if(myPlayer.getHand().at(i).getColour().compare("Azul") == 0 ) {
          blueCards++;
        }
      }

      return blueCards;
    }

    int findYellowCards(Player* players, int position) {
      int yellowCards = 0;
      Player myPlayer = players[position];

      for(int i = 0; i < myPlayer.getNumberCards(); i++) {
        if(myPlayer.getHand().at(i).getColour().compare("Amarela") == 0 ) {
          yellowCards++;
        }
      }

      return yellowCards;
    }

    int findRedCards(Player* players, int position) {
      int redCards = 0;
      Player myPlayer = players[position];

      for(int i = 0; i < myPlayer.getNumberCards(); i++) {
        if(myPlayer.getHand().at(i).getColour().compare("Vermelha") == 0 ) {
          redCards++;
        }
      }

      return redCards;
    }

    int findGreenCards(Player* players, int position) {
      int greenCards = 0;
      Player myPlayer = players[position];

      for(int i = 0; i < myPlayer.getNumberCards(); i++) {
        if(myPlayer.getHand().at(i).getColour().compare("Verde") == 0 ) {
          greenCards++;
        }
      }

      return greenCards;
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

    void chooseCards(Player* players, int position, bool reversed, Card upCard){
        Player myPlayer = players[position];

        for(int i=0; i<myPlayer.getNumberCards(); i++){
            if(checkCard(myPlayer.getHand().at(i), upCard)){

                if(myPlayer.getHand().at(i).getEffect().compare("+4")==0)
                    positionFour=i+1;
                if(myPlayer.getHand().at(i).getEffect().compare("+2")==0)
                    positionTwo=i+1;
                if(myPlayer.getHand().at(i).getEffect().compare("reversed")==0)
                    positionReversed=i+1;
                if(myPlayer.getHand().at(i).getEffect().compare("blocked")==0)
                    positionBlocked=i+1;
                if(myPlayer.getHand().at(i).getEffect().compare("newColour")==0)
                    positionNewColour=i+1;
                if(myPlayer.getHand().at(i).getEffect().compare("")==0)
                    positionNormalCard=i+1;
            }
        }
    }

    bool checkCard(Card cardHand, Card upCard){
        if(cardHand.getColour().compare(upCard.getColour())==0){
            return true;
        }
        if(cardHand.getNumber()==upCard.getNumber()){
            return true;
        }
        if(cardHand.getColour().compare("Preta")==0||cardHand.getEffect().compare("newColour")==0 || cardHand.getEffect().compare("+4")==0){
            return true;
        }
            return false;
    }


private:
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

    int positionFour=0;
    int positionTwo=0;
    int positionBlocked=0;
    int positionReversed=0;
    int positionNormalCard=0;
    int positionNewColour=0;

};
