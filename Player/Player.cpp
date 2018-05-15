#include<iostream>
#include<string>
#include<vector>
#pragma once
using namespace std;

#include "../Baralho/Deck.cpp"


class Player{

public: Player(string name){
        setNome(name);
    }
        Player(){}

    string getNome(){
        return name;
    }

    void setNome(string newName){
        name = newName;
    }


    void addCard(Card card){
        hand.push_back(card);
    }

    Card dropCard(int position){
        Card card = hand[position-1];
        hand.erase(hand.begin()+position-1);
        return card;
    }

    int getNumberCards(){
        return hand.size();
    }

    vector<Card> getHand(){
        return hand;
    }

    void toString() const{
        cout << "Player --> Name:" << name;
    }

    void showHand(){
        for(int i=0; i<hand.size(); i++)
            cout << hand.at(i).getNumber() << " " << hand[i].getColour() << endl;
    }

private:
    string name;
    vector <Card> hand;
};


int main(){
    Player player("matheus");
    Deck deck;
    deck.starting();
    Card card(1, "Azul");
    deck.addCard(card);
    player.addCard(deck.pullCard());
    player.showHand();
    player.dropCard(1);
    cout << player.getNumberCards();

}
