#include <string>

#ifndef blackjack_h_
#define blackjak_h_

// -----------------------------------------------------------------
// BLACKJACK PLAYER CLASS!
class BlackJackPlayer {

    enum pType { Player, CPU, Dealer, NONE };

    public:
        BlackJackPlayer(){
            name = "PLAYERDEF";
            type = Player;
            playerNum = 1;
            score = 100;
            wager = 0;
        }

        //accessors
        std::string getName() { return name; }
        pType getType() { return type; }
        int getPlayerNum() { return playerNum; }
        int getScore() { return score; }
        int getWager() { return wager; }

        //setters
        void setName(std::string n) { name = n; }
        void setType(pType t) { type = t; }
        void setPlayerNum(int p) { playerNum = p; }
        void setScore(int s) { score = s; }
        void setWager(int w) { wager = w; }

    private:
        std::string name;
        pType type;
        int playerNum;
        int score;
        int wager;
};

// -----------------------------------------------------------------
// BLACKJACK GAME CLASS!
class BlackJackGame {

    public:
        void setGameType(pType type, int count);
        int numPlayers();
        void fillSeats();
        void playDealer();
        void printDealer();
        void playPlayer();
        void printPlayer();
        void printTurn();
        void choicePlayer();
        void choiceDealer();
        void printResults();
        void checkWin();
        void setPlayerName(std::string name);

    private:
        BlackJackPlayer p1;
        BlackJackPlayer p2;
        BlackJackPlayer p3;
        BlackJackPlayer p4;
        BlackJackPlayer dealer;
};

#endif