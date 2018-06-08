#include<iostream>
#include<string>
#include <typeinfo>
#pragma once

using namespace std;

#include "../Player/Player.cpp"
#include "../Baralho/Deck.cpp"
#include "../Baralho/Card.cpp"
#include "../Player/botLogic.cpp"
#include "../structs.h"


/*
Método que checa se determinada carta de um player pode ser jogada no deck principal!
*/
    bool checkCardSystem(Card cardHand, Card upCard){
        if(cardHand.colour.compare(upCard.colour)==0){
            return true;
        }
        if(cardHand.number==upCard.number){
            return true;
        }
        if(cardHand.colour.compare("Preta") == 0 || cardHand.effect.compare("newColour")==0 || cardHand.effect.compare("+4")==0){
            return true;
        }

            return false;
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

    void AddToSpecialcard(Deck &deck, Player* players, int position, int value){
        if(getCardsInDeck(deck) > value){
            for(int k=0; k<value; k++){
                addCard(pullCard(deck), players[position]);
            }
        }
    }


    void fourCardOrTwoCard(Deck &deck, Player* players, int position, int value){
        AddToSpecialcard(deck, players, position, value);
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
          specialCard.colour = (newColour);
          break;
        }

      }

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

    void gameRoutation(Card &specialCard, Deck &deck, Player* players, int &position, bool &reversed){
        if(specialCard.effect.compare("blocked") == 0) {
            foundBlockedCard(position);

        } else if(specialCard.effect.compare("reversed") == 0){
            foundReversedCard(reversed);
            normalMoviment(position, reversed);

        }else if(specialCard.effect.compare("+4") == 0){
          if(position == 1) {
            tradeColorIn4(specialCard);
          } else {
            specialCard.colour = chooseBestColour(players, position);
          }

          normalMoviment(position, reversed);
          fourCardOrTwoCard(deck, players, position, 4);

        }else if(specialCard.effect.compare("+2") == 0){
            normalMoviment(position, reversed);

            fourCardOrTwoCard(deck, players, position, 2);
        }else if(specialCard.effect.compare("newColour") == 0) {
          if(position == 1) {
            tradeColorIn4(specialCard);
          } else {
            specialCard.colour = chooseBestColour(players, position);
          }

          normalMoviment(position, reversed);

        }else{
            normalMoviment(position, reversed);
        }
    }


/*Método usado para um player joga uma carta do deck principal, caso o mesmo tenha uma carta
 compatível com a última carta do deck principal!
*/
    void playCard(Player* players, Card upCard, Deck &primaryDeck, Deck &secundaryDeck, int &positionRoutation, bool &reversed){
        while(1){
            int position;

            if(positionRoutation == 1) {
              scanf("%d", &position);
            } else {
              position = logistic(players, positionRoutation, reversed, upCard);
            }

            if(getNumberCards(players[positionRoutation]) >= position) {
              if(checkCardSystem(players[positionRoutation].hand.at(position-1), upCard)){
                  Card playedCard = dropCard(players[positionRoutation], position);
                  gameRoutation(playedCard, primaryDeck, players, positionRoutation, reversed);
                  addCard(playedCard, secundaryDeck);
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
        for(int i=0; i<getNumberCards(players[position]); i++){
            if(players[position].hand.at(i).number == upCard.number){
                return true;
            }else if(players[position].hand.at(i).colour.compare(upCard.colour)==0){
                return true;
            }else if(players[position].hand.at(i).colour.compare("Preta")==0){
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
        Card newCard = pullCard(deck);

        if(checkCardSystem(newCard, getDeck(outDeck)[0])) {
          gameRoutation(newCard, deck, players, position, reversed);
          addCard(newCard, outDeck);
        } else {
            addCard(newCard, players[position]);
        }
    }










