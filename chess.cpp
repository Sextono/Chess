#include <iostream>
#include <vector>

#include "chess.hpp"
#include "board.hpp"

// void board::settings(){
//     while(1){
//         std::cout << "Settings have not been implemented yet" << std::endl;
//         int choice;
//         std::cout << "Enter 0 to start game: ";
//         std::cin >> choice;
//         if (choice == 0) break;
//     }
// }

void startGame(board* b){
    std::cout << std::endl << std::endl << "Loading game . . ." << std::endl << std::endl << std::endl;
    b->settings();
    b->play();
}
