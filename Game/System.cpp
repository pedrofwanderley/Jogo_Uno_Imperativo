#include<iostream>
#include<string>
#include <typeinfo>
#pragma once

using namespace std;

#include "../Player/Player.cpp"
#include "../Baralho/Deck.cpp"
#include "../Baralho/Card.cpp"
#include "../Player/botLogic.cpp"

/*
Classe que representa o sistema de jogo, com métodos que representam as ações que podem ser
tomadas ou realizadas durante as partidas!
*/
class System{
public: System(){}
/*
Método usado para um player joga uma carta do deck principal, caso o mesmo tenha uma carta
 compatível com a última carta do deck principal!
*/
    void playCard(Player* players, Card upCard, Deck &primaryDeck, Deck &secundaryDeck, int &positionRoutation, bool &reversed){
        while(1){
            int position;

            if(positionRoutation == 1) {
              scanf("%d", &position);
            } else {
              position = bot.logistic(players, positionRoutation, reversed, upCard);
            }

            if(players[positionRoutation].getNumberCards() >= position) {
              if(checkCard(players[positionRoutation].getHand().at(position-1), upCard)){
                  Card playedCard = players[positionRoutation].dropCard(position);
                  gameRoutation(playedCard, primaryDeck, players, positionRoutation, reversed);
                  secundaryDeck.addCard(playedCard);
                  break;
                }
            }

            cout << "Tente outra carta!" << endl;

        }
    }


/*
Método que checa se o determinado player tem uma carta que seja jogável na rodada!
*/
    bool haveCard(Player* players, Card upCard, int position){
        for(int i=0; i<players[position].getNumberCards(); i++){
            if(players[position].getHand().at(i).getNumber() == upCard.getNumber()){
                return true;
            }else if(players[position].getHand().at(i).getColour().compare(upCard.getColour())==0){
                return true;
            }else if(players[position].getHand().at(i).getColour().compare("Preta")==0){
                return true;
            }
        }
                return false;
    }
/*
Método pegar e jogar, usado quando um player não tem uma carta para jogar, porém ao puxar
uma carta do deck a carta retirada pode ser jogada no deck principal!! Caso não possa ser jogada
a carta é direcionada para o deck do player!
*/
    void pickAndPlay(Player* players, int &position, Deck &deck, Deck &outDeck, bool &reversed){
        Card newCard = deck.pullCard();

        if(checkCard(newCard, outDeck.getDeck()[0])) {
          gameRoutation(newCard, deck, players, position, reversed);
          outDeck.addCard(newCard);

        } else {
            players[position].addCard(newCard);
        }
    }

    // COMO SERÁ DEFINIDA A CARTA PRA BLOQUEAR == BLOCKED
    // COMO SERA DEFINIDA CARTA +4 == +4
    // COMO SERA DEFINIDA A CARTA +2 == +2
    void gameRoutation(Card &specialCard, Deck &deck, Player* players, int &position, bool &reversed){
        if(specialCard.getEffect().compare("blocked") == 0) {
            foundBlockedCard(position);

        } else if(specialCard.getEffect().compare("reversed") == 0){
            foundReversedCard(reversed);
            normalMoviment(position, reversed);

        }else if(specialCard.getEffect().compare("+4") == 0){
          if(position == 1) {
            tradeColorIn4(specialCard);
          } else {
            specialCard.setColour(bot.chooseBestColour(players, position));
          }

          normalMoviment(position, reversed);
          fourCardOrTwoCard(deck, players, position, 4);

        }else if(specialCard.getEffect().compare("+2") == 0){
            normalMoviment(position, reversed);

            fourCardOrTwoCard(deck, players, position, 2);
        }else if(specialCard.getEffect().compare("newColour") == 0) {
          if(position == 1) {
            tradeColorIn4(specialCard);
          } else {
            specialCard.setColour(bot.chooseBestColour(players, position));
          }

          normalMoviment(position, reversed);

        }else{
            normalMoviment(position, reversed);
        }
    }

/*
Método de escolha de cor para um player que jogar uma carta especial
*/
    void tradeColorIn4(Card &specialCard){
      string newColour;
      string vazio;

      while(1) {
        printf("Selecione uma nova cor: Verde, Azul, Amarela ou Vermelha");
        cout << endl;

        getline(cin, vazio);
        getline(cin, newColour);

        if(newColour.compare("Verde") == 0 || newColour.compare("Azul") == 0 || newColour.compare("Vermelha") == 0 || newColour.compare("Amarela") == 0) {
          specialCard.setColour(newColour);
          break;
        }

      }

    }
/*
Método que determina o fluxo do jogo, dependendo da carta jogada!
*/
    void normalMoviment(int &position, bool reversed){
        if(reversed){
            if(position == 1)
                position = 4;
            else
                position--;
        }else{
            if(position == 4)
                position = 1;
            else
                position++;
        }
    }


/*
Método que checa se uma carta de reversão de jogada foi inserida!
*/
    void foundReversedCard(bool &reversed){
        if(reversed)
            reversed = false;
        else
            reversed = true;
    }
/*
Método que checa se uma carta de bloqueio foi inserida!
*/
    void foundBlockedCard(int &position){
            if(position > 2)
                position = position-2;
            else
                position = position+2;
    }

    void fourCardOrTwoCard(Deck &deck, Player* players, int position, int value){
        AddToSpecialcard(deck, players, position, value);
    }

    void AddToSpecialcard(Deck &deck, Player* players, int position, int value){
        if(deck.getCardsInDeck() > value){
            for(int k=0; k<value; k++){
                players[position].addCard(deck.pullCard());
            }
        }
    }



private:
    Player player[4];
    botLogic bot;
/*
Método que checa se determinada carta de um player pode ser jogada no deck principal!
*/
    bool checkCard(Card cardHand, Card upCard){
        if(cardHand.getColour().compare(upCard.getColour())==0){
            return true;
        }
        if(cardHand.getNumber()==upCard.getNumber()){
            return true;
        }
        if(cardHand.getColour().compare("Preta") == 0 || cardHand.getEffect().compare("newColour")==0 || cardHand.getEffect().compare("+4")==0){
            return true;
        }

            return false;
    }

};
