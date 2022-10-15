#include <iostream>
#include <string>

#include "blackjack.h"

void start_blackjack();
int play_blackjack(int tr, int cr, BlackJackGame blackjakky);

enum pType { Player, CPU, Dealer, NONE };

int main(){
    int choice;
    std::cout << "Welcome to Ali's Casino! What would you like to play? (enter a number)" << std::endl;
    std::cout << "    1. BlackJack" << std::endl;
    std::cout << "    2. Exit the casino" << std::endl;
    std::cout << "> ";
    std::cin >> choice;
    if(choice == 1){
        start_blackjack();
    }
    else if(choice == 2){
        std::cout << "Thanks for stopping by!" << std::endl;
        exit(0);
    }
    else{
        std::cout << "I didn't quite catch that, lets try again." << std::endl;
        std::cout << std::endl;
        main();
    }

}

void start_blackjack(){
    //player count
    //round count or infinite

    int choice;
    std::cout << "Welcome to BMan's BlackJack! Would you like to play?" << std::endl;
    std::cout << "    1. Yes" << std::endl;
    std::cout << "    2. No (Head back to lobby)" << std::endl;
    std::cout << "> ";
    std::cin >> choice;
    if(choice == 1){
        std::cout << "Great! Let's get started!" << std::endl;
    }
    else if(choice == 2){
        std::cout << "Thanks for stopping by!" << std::endl;
        std::cout << std::endl;
        main();
    }
    else{
        std::cout << "I didn't quite catch that, lets try again." << std::endl;
        std::cout << std::endl;
        start_blackjack();
    }

    //maybe add how to play

    BlackJackGame blackjackky;

    std::cout << "How would you like to play?" << std::endl;
    std::cout << "    1. Alone" << std::endl;
    std::cout << "    2. Alone w/ CPUs" << std::endl;
    std::cout << "    3. You w/ friends" << std::endl;
    std::cout << "> ";
    std::cin >> choice;
    if(choice == 1){
        std::cout << "Alright! It's just you versus the dealer!" << std::endl;
        blackjackky.setGameType(Player, 1);
    }
    else if(choice == 2){
        std::cout << "How many CPUs?" << std::endl;
        std::cout << "    1. One CPU" << std::endl;
        std::cout << "    2. Two CPUs" << std::endl;
        std::cout << "    3. Three CPUs" << std::endl;
        std::cout << "> ";
        std::cin >> choice;
        if(choice == 1){
            std::cout << "One CPU it is!" << std::endl;
            blackjackky.setGameType(CPU, 1);
        }
        else if(choice == 2){
            std::cout << "Two CPUs it is!" << std::endl;
            blackjackky.setGameType(CPU, 2);
        }
        else if(choice == 3){
            std::cout << "Three CPUs it is!" << std::endl;
            blackjackky.setGameType(CPU, 3);
        }
        else{
            std::cout << "I didn't quite catch that, lets default to three." << std::endl;
            blackjackky.setGameType(CPU, 3);
        }

    }
    else if(choice == 3){
        std::cout << "How many friends?" << std::endl;
        std::cout << "    1. One friend" << std::endl;
        std::cout << "    2. Two frinds" << std::endl;
        std::cout << "    3. Three friends" << std::endl;
        std::cout << "> ";
        std::cin >> choice;
        if(choice == 1){
            std::cout << "One friend it is!" << std::endl;
            blackjackky.setGameType(Player, 2);
        }
        else if(choice == 2){
            std::cout << "Two friends it is!" << std::endl;
            blackjackky.setGameType(Player, 3);
        }
        else if(choice == 3){
            std::cout << "Three friends it is!" << std::endl;
            blackjackky.setGameType(Player, 4);
        }
        else{
            std::cout << "I didn't quite catch that, lets default to one." << std::endl;
            blackjackky.setGameType(Player, 1);
        }

        std::string name;
        for(int i = 1; i <=blackjakky.numPlayers(); i++){
            std::cout << "What is friend #" << i << "'s name?" << std::endl;
            std::cout << "> ";
            std::cin >> name;
            blackjakky.setPlayerName(i, name);
        }
        if(blackjakky.numPlayers() < 4){
            std::cout << "Would you like to fill the " << 4-blackjakky.numPlayers() << " empty seats with CPUs?" << std::endl;
            std::cout << "    1. Yes" << std::endl;
            std::cout << "    2. No" << std::endl;
            std::cout << "> ";
            std::cin >> choice;
        }
        if(choice == 1){
            std::cout << "Got it! Filling seats!" << std::endl;
            blackjackky.fillSeats();
        }
        else if(choice == 2){
            std::cout << "Got it! No CPUs." << std::endl;
        }
        else{
            std::cout << "I didn't quite catch that, lets default to filling seats." << std::endl;
            blackjackky.fillSeats();
        }
    }
    else{
        std::cout << "I didn't quite catch that, lets try again." << std::endl;
        std::cout << std::endl;
        start_blackjack();
    }

    int rounds = -1;
    std::cout << "How many rounds? Type the ammount or type -1 for infinite" << std::endl;
    std::cout << "    1. Five Rounds" << std::endl;
    std::cout << "    2. Ten Rounds" << std::endl;
    std::cout << "    3. Infinite" << std::endl;
    std::cout << "> ";
    std::cin >> choice;
    if(choice == 0){
        std::cout << "0 rounds? Then I suppose you dont want to play. Thank you for visiting!" << std::endl;
        std::cout << std::endl;
        main();
    }
    else{
        std::cout << "Got it! ";
        if(choice < 0){
            std::cout << "Infinite rounds!" << std::endl;
        }
        else{
            std::cout << choice << " rounds!" << std::endl;
        }
        rounds = choice;
    }

    std::cout << "That's all! Lets play blackjack!" << std::endl;
    std::cout << std::endl;
    play_blackjack(rounds, 0, blackjakky);
    

    
    

    //start blackjack!
/*
*-----------------------------------------------------------------------------------* //PRINTDEALER
|                                                                                   |
|                                      DEALER                                       |
|                                   10/10/10/10/10                                  |
|                                         = 21                                      |
|                                                                                   | //PRINTDEALER
*--------------------*--------------------*--------------------*--------------------* //PRINTPLAYERS
|  player            |      wild woody    |   davyjone         |       will         |
|                    |                    |                    |                    |
|total: 10000000000  |                    |                    |                    |
|                    |                    |                    |                    |
|10/10/10/10/10      |                    |                    |                    |
|= 22 (bust!)        |                    |                    |                    |
*--------------------*--------------------*--------------------*--------------------* //PRINTPLAYERS
PLAYER's TURN!
round: 6/infinite

*/

}

int play_blackjack(int trounds, int crounds, BlackJackGame blackjakky){

    blackjakky.playDealer();
    blackjakky.printDealer();
    for(int i = 1; i != blackjakky.numPlayers(); i++){
        blackjakky.playPlayer(i);
        blackjakky.printPlayer(i);

        blackjakky.printTurn(i);

        std::cout << "round: " << crounds << "/";
        if(trounds < 0){
            std::cout << "infinite";
        }
        else{

        }

        blackjakky.choicePlayer(i);
    }

    blackjakky.choiceDealer();

    for(int i = 1; i != blackjakky.numPlayers(); i++){
        blackjakky.checkWin(i);
    }

    std::cout << "Enter anything to proceed to next round." << std::endl;
    std::cout << "> ";
    std::cin;

    if(crounds == trounds){
        blackjakky.printResults();
        between_lobby();
    }
    else{
        play_blackjack(trounds, crounds++, blackjakky);
    }
}
