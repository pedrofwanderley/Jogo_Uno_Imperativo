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

    void rotationPlay(Deck &deck, Players[] &players, int &position, bool reversed, Card specialCard){
        switch(position){
            case 1:
                searchTheSpecialCard(specialCard, deck, players, 1, reversed)
                break;
            case 2:
                searchTheSpecialCard(specialCard, deck, players, 2, reversed)
                break;
            case 3:
                searchTheSpecialCard(specialCard, deck, players, 3, reversed)
                break;
            case 4:
                searchTheSpecialCard(specialCard, deck, players, 4, reversed)
                break;
        }
    }
    // COMO SERÁ DEFINIDA A CARTA PRA BLOQUEAR == BLOCKED
    // COMO SERA DEFINIDA CARTA +4 == +4
    // COMO SERA DEFINIDA A CARTA +2 == +2
    void searchTheSpecialCard(Card specialCard, Deck &deck, Players &players[], int &position, bool reversed){
        if(specialCard == blocked){
            if(position > 2)
                position = position-2;
            else
                position = position+2;
        }else if(reversed){
            if(position == 1)
                position = 4;
            else
                position--;
            fourCardOrTwoCard(deck, players, position);
        }else{
            position = 1;
            if(position == 4)
                position = 1;
            else
                position++;
            fourCardOrTwoCard(deck, players, position);
        }
    }

    void fourCardOrTwoCard(Deck deck, Players[] players, int &position, int value){
        if(specialCard == +4){
                AddToSpecialcard(deck, players, 2, 4);
        }
        if(specialCard == +2){
                AddToSpecialcard(deck, players, 2, 2);
        }
    }

    void AddToSpecialcard(Deck &deck, Players[] &players, int position, int value){
        for(int i=0; i<value; i++){
            players[position].addCard(deck.pullCard());
        }
    }



private:

    bool checkCard(Card cardHand, Card upCard){
        if(cardHand.getColour().compare(upCard.getColour())==0){
            return true;
        }
        if(cardHand.getNumber()==upCard.getNumber()){
            return true;
        }
        if (cardHand == specialCard && specialCard.getEffect == "+4") {
          return true;
        }
        if (cardHand == specialCard && specialCard.getEffect == "newColour") {
          return true;
        }
            return false;
    }

};
