#include <iostream>
#include "chess.hpp"
#include "board.hpp"



int main() {
    int choice;
    board* b = new board;
    std::cout << "Welcome!" << std::endl;
    while (choice != 1 ){
        std::cout << "What would you like to do?" << std::endl << "1. Start Game" << std::endl << "2. Log In or Create Account" << std::endl << "3. View Rules" << std::endl << "4. View Stats and Past Games" << std::endl;
        std::cout << "Choice: ";
        std::cin >> choice;
        if (choice == 1){
            startGame(b);
            choice = 0;
        }
        else if (choice == 2) std::cout << "Account services are not implemented yet. Please check back later." << std::endl;
        else if (choice == 3) rules();
        else if (choice == 4) std::cout << "Stats are not implemented yet. Please check back later." << std::endl;
        else{
            std::cout << "Please enter a number between 1 and 4: ";
        }
    }
    return 0;
}