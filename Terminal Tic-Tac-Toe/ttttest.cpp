//Terminal Tic-Tac-Toe
//Seth Opatz
//08-16-24

#include <iostream>
#include "ttthead.hpp"

int main() {
    std::cout << std::endl; //spacing to look nice in the terminal
    board game;
    while (!game.isGameDone()) {
        game.turn();
        std::cout << "Current Board: \n" << std::endl;
        game.printBoard();
    }
    std::cout << std::endl; //spacing to look nice in the terminal
    return 0;
}