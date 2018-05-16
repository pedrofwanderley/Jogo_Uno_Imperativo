#include<iostream>
#include<string>
#include <typeinfo>

using namespace std;

#include "../Player/player.cpp"
#include "../Baralho/deck.cpp"


class System{
public: System(){}
    void playCard(Player &player, Card upCard, Deck &primaryDeck, Deck &secundaryDeck){
        while(1){
            int position;
            scanf("%d", &position);
            if(checkCard(player.getHand().at(position-1), upCard)){
                secundaryDeck.addCard(player.dropCard(position));
                break;
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


private:

    bool checkCard(Card cardHand, Card upCard){
        if(cardHand.getColour().compare(upCard.getColour())==0){
            return true;
        }
        if(cardHand.getNumber()==upCard.getNumber()){
            return true;
        }
            return false;
    }

};
