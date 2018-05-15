#include<iostream>
#include<string>
#include <typeinfo>

using namespace std;

#include "../Player/player.cpp"
#include "../Baralho/deck.cpp"


class system{
public: system(){}
    void playCard(Player player, Card upCard, Deck primaryDeck, Deck secundaryDeck, int position){
        if(haveCard(player, upCard)){
            while(1){
                if(checkCard(player.getHand().at(position), upCard)){
                    secundaryDeck.addCard(player.dropCard(position));
                }else{
                    break;
                }
            }
        }else{
            player.addCard(primaryDeck.pullCard());
        }
    }

    bool checkCard(Card cardHand, Card upCard){
        if(cardHand.getColour().compare(upCard.getColour())==0){
            return true;
        }else if(cardHand.getNumber()==upCard.getNumber()){
            return true;
        }else{
            return false;
        }
    }


    bool haveCard(Player player, Card upCard){
        for(int i=0; i<player.getNumberCards(); i++){
            if(player.getHand().at(i).getNumber()==upCard.getNumber()){
                return 1;
            }else if(player.getHand().at(i).getColour().compare(upCard.getColour()) == 0){
                return 1;
            }
        }
                return 0;
    }


private:
    Player player1;
    Player player2;
    Player player3;
    Player player4;
    Deck primaryDeck;
    Deck secundaryDeck;
    bool hourRotation=true;

};

