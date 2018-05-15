#include<iostream>
#include<string>
#include<vector>
#pragma once
using namespace std;

#include "../Baralho/Deck.cpp"


class Player{

public: Player(int id){
        setId(id);
    }
        Player(){}


    void addCard(Card card){
        hand.push_back(card);
    }



    int getNumberCards(){
        return hand.size();
    }

    vector<Card> getHand(){
        return hand;
    }

    void toString() const{
        cout << "Player --> Name:" << id;
    }

    void showHand(){
        for(int i=0; i<hand.size(); i++)
            cout << hand.at(i).getNumber()-1 << " " << hand[i].getColour() << endl;
    }

    void setId(int newId) {
      id = newId;
    }

    int getId() {
      return id;
    }

    Card dropCard(int position){
        Card card = hand[position-1];
        hand.erase(hand.begin()+position-1);
        return card;
    }

protected:
    vector <Card> hand;
    int id;
};


/**int main(){
    Player player("matheus");
    Deck deck;
    deck.starting();
    Card card(1, "Azul");
    deck.addCard(card);
    player.addCard(deck.pullCard());
    player.showHand();
    player.dropCard(1);
    cout << player.getNumberCards();

}*/
