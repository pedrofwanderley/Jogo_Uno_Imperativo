#include<iostream>
#include<string>
#include<vector>
#pragma once
using namespace std;

#include "../Baralho/Card.cpp"
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

    void dropCard(int position){
        hand.erase(hand.begin()+position-1);
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

private:
    string name;
    vector <Card> hand;
};


int main(){
    Player player("matheus");
    Deck deck;
    deck.starting();
    player.addCard(deck.pullCard());
    player.dropCard(1);
    cout << player.getNumberCards();

}
