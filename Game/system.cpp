#include<iostream>
#include<string>
#include <typeinfo>
#pragma once

using namespace std;

#include "../Player/player.cpp"
#include "../Baralho/deck.cpp"
#include "../Baralho/SpecialCard.cpp"
#include "../Baralho/Card.cpp"


class System{
public: System(){}
    void playCard(Player* players, Card upCard, Deck &primaryDeck, Deck &secundaryDeck, int &positionRoutation, bool &reversed){
        while(1){
            int position;
            scanf("%d", &position);
            if(checkCard(players[positionRoutation].getHand().at(position-1), upCard)){
                Card playedCard = players[positionRoutation].dropCard(position);
                gameRoutation(playedCard, primaryDeck, players, positionRoutation, reversed);
                secundaryDeck.addCard(playedCard);
                break;
            }
            //Jogandp carta especial +4
            /*if(player.getHand().at(position-1).getEffect().compare("+4")){
              string colour;
              scanf("%s", &colour);
              upCard.setColour(&colour);
              secundaryDeck.addCard(player.dropCard(position));
            }*/
        }
    }



    bool haveCard(Player* players, Card upCard, int position){
        for(int i=0; i<players[position].getNumberCards(); i++){
            if(players[position].getHand().at(i).getNumber()==upCard.getNumber()){
                return true;
            }else if(players[position].getHand().at(i).getColour().compare(upCard.getColour())==0){
                return true;
            }
        }
                return false;
    }

    void pickAndPlay(Player &player, Deck &deck, Deck &outDeck){
        Card newCard = deck.pullCard();
        if(checkCard(newCard, outDeck.getDeck()[outDeck.getCardsInDeck()-1]))
            outDeck.addCard(newCard);
        else
            player.addCard(newCard);
    }

    // COMO SERÁ DEFINIDA A CARTA PRA BLOQUEAR == BLOCKED
    // COMO SERA DEFINIDA CARTA +4 == +4
    // COMO SERA DEFINIDA A CARTA +2 == +2
    void gameRoutation(Card &specialCard, Deck &deck, Player* players, int &position, bool &reversed){
        if(specialCard.getEffect().compare("blocked")==0)
            foundBlockedCard(position);
        else if(specialCard.getEffect().compare("reversed")==0)
            foundReversedCard(reversed);
        else if(specialCard.getEffect().compare("+4")==0){
            normalMoviment(position, reversed);
            fourCardOrTwoCard(deck, players, position, 4);
            tradeColorIn4(specialCard);
        }else if(specialCard.getEffect().compare("+2")==0){
            normalMoviment(position, reversed);
            fourCardOrTwoCard(deck, players, position, 2);
        }else{
            normalMoviment(position, reversed);
        }
    }

    void tradeColorIn4(Card &specialCard){
        specialCard.setEffect("Verde");
    }

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



    void foundReversedCard(bool &reversed){
        if(reversed)
            reversed = false;
        else
            reversed = true;
    }

    void foundBlockedCard(int &position){
            if(position > 2)
                position = position-2;
            else
                position = position+2;
    }

    void fourCardOrTwoCard(Deck deck, Player* players, int position, int value){
        AddToSpecialcard(deck, players, position, value);
    }

    void AddToSpecialcard(Deck &deck, Player* players, int position, int value){
        for(int i=0; i<value; i++){
            players[position].addCard(deck.pullCard());
        }
    }



private:
    Player player[4];

    bool checkCard(Card cardHand, Card upCard){
        if(cardHand.getColour().compare(upCard.getColour())==0){
            return true;
        }
        if(cardHand.getNumber()==upCard.getNumber()){
            return true;
        }
        /*if (typeid(cardHand) == SpecialCard && specialCard.getEffect == "+4") {
          return true;
        }
        if (typeid(cardHand) == SpecialCard && specialCard.getEffect == "newColour") {
          return true;
        }*/
            return false;
    }

};
