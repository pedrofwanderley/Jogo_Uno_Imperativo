#include<iostream>
#include<string>
#include<vector>
#pragma once
using namespace std;

#include "../Baralho/Deck.cpp"
#include "../structs.h"

/*
Método que adiciona uma carta no deck do player.
*/
    void addCard(Card card, Player &player){
        player.hand.push_back(card);
    }



    int getNumberCards(Player &player){
        return player.hand.size();
    }

    vector<Card> getHand(Player &player){
        return player.hand;
    }

/*
Método de exibição de cartas de um determinado Player
*/
    void showHand(Player &player){
        for(int i=0; i<player.hand.size(); i++){
            if (player.hand[i].effect.compare("") == 0)
                cout << i+1 << " - " << player.hand.at(i).number << " " << player.hand[i].colour << " " << player.hand[i].effect << endl;
            else
                cout << i+1 << " - " << player.hand[i].colour << " " << player.hand[i].effect << endl;
        }
    }
/*
Método que representa a retirada de uma carta do deck de um determinado player.
*/
  Card dropCard(Player &player, int position){
        Card card = player.hand[position-1];
        player.hand.erase(player.hand.begin()+position-1);
        return card;
  }

