#include <iostream>
using namespace std;



class Bot: public Player {
public:
  Bot(int id):Player(id){

  }

  void play(Player enemy) {
    if(enemyIsAboutToWin(enemy)) {
      int specialCard = findSpecialCard();

      if(specialCard != -1) {
        // Se tiver uma carta especial, vai joga-la

      }
    }

    // Se o jogador inimigo nao tiver prestes a ganhar, ele joga a primeira carta possivel.
  }


private:
  bool enemyIsAboutToWin(Player enemy) {
    if(enemy.getNumberCards() == 1 || enemy.getNumberCards() == 2) {
      return true;
    }

    return false;
  }

  int findSpecialCard() {

    for(int i = 0; i < hand.size(); i++) {
      if(hand.getAt(i).getEffect().compare("blocked") == 0){
          return i;
      }else if(hand.getAt(i).getEffect().compare("reversed") == 0){
          return i;normalPlay();
      }else if(hand.getAt(i).getEffect().compare("+4") == 0){
          return i;
      }else if(hand.getAt(i).compare("+2") == 0){
          return i;
      }
    }

    return -1;
  }


};
