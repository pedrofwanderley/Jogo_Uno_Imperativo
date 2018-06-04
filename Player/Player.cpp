#include<iostream>
#include<string>
#include<vector>
#pragma once
using namespace std;

#include "../Baralho/Deck.cpp"

/*
Classe que representa um player no jogo
*/
class Player{

public: Player(int id){
        setId(id);
    }
        Player(){}

/*
Método que adiciona uma carta no deck do player.
*/
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
/*
Método de exibição de cartas de um determinado Player
*/
    void showHand(){
        for(int i=0; i<hand.size(); i++)
            cout << hand.at(i).getNumber() << " " << hand[i].getColour() << " " << hand[i].getEffect() << endl;
    }

    void setId(int newId) {
      id = newId;
    }

    int getId() {
      return id;
    }
/*
Método que representa a retirada de uma carta do deck de um determinado player.
*/
  Card dropCard(int position){
        Card card = hand[position-1];
        hand.erase(hand.begin()+position-1);
        return card;
  }

protected:
    vector <Card> hand;
    int id;
};
