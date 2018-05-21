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
    void playCard(Player* players, Card upCard, Deck &primaryDeck, Deck &secundaryDeck){
        while(1){
            int position;
            scanf("%d", &position);
            if(checkCard(players[0].getHand().at(position-1), upCard)){
                Card playedCard = players[0].dropCard(position);
                searchTheSpecialCard(playedCard, primaryDeck, players, 0, true);
                secundaryDeck.addCard(playedCard);
                break;
            }
            //Jogandp carta especial +4
            if(player.getHand().at(position-1).getEffect().compare("+4")){
              string colour;
              scanf("%s", &colour);
              upCard.setColour(&colour);
              secundaryDeck.addCard(player.dropCard(position));
            }

        }
    }



    bool haveCard(Player &player, Card upCard){
        for(int i=0; i<player.getNumberCards(); i++){
            if(player.getHand().at(i).getNumber()==upCard.getNumber()){
                return true;
            }else if(player.getHand().at(i).getColour().compare(upCard.getColour())==0){
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

    void rotationPlay(Deck &deck, Player* players, int &position, bool reversed, SpecialCard specialCard){
        switch(position){
            case 1:
                searchTheSpecialCard(specialCard, deck, players, position, reversed);
                break;
            case 2:
                searchTheSpecialCard(specialCard, deck, players, position, reversed);
                break;
            case 3:
                searchTheSpecialCard(specialCard, deck, players, position, reversed);
                break;
            case 4:
                searchTheSpecialCard(specialCard, deck, players, position, reversed);
                break;
        }
    }
    // COMO SERÁ DEFINIDA A CARTA PRA BLOQUEAR == BLOCKED
    // COMO SERA DEFINIDA CARTA +4 == +4
    // COMO SERA DEFINIDA A CARTA +2 == +2
    void searchTheSpecialCard(Card specialCard, Deck &deck, Player* players, int &position, bool reversed){
        if(specialCard.getEffect().compare("blocked")){
            if(position > 2)
                position = position-2;
            else
                position = position+2;
        }else if(reversed){
            if(position == 1)
                position = 4;
            else
                position--;
            fourCardOrTwoCard(specialCard, deck, players, position);
        }else{
            position = 1;
            if(position == 4)
                position = 1;
            else
                position++;
            fourCardOrTwoCard(specialCard, deck, players, position);
        }
    }

    void fourCardOrTwoCard(SpecialCard specialCard, Deck deck, Player* players, int position){
        if(specialCard.getEffect().compare("+4")){
                AddToSpecialcard(deck, players, position, 4);
        }
        if(specialCard.getEffect().compare("+2")){
                AddToSpecialcard(deck, players, position, 2);
        }
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
        if (typeid(cardHand) == SpecialCard && specialCard.getEffect == "+4") {
          return true;
        }
        if (typeid(cardHand) == SpecialCard && specialCard.getEffect == "newColour") {
          return true;
        }
            return false;
    }

};
