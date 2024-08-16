#include "ttthead.hpp"
#include <iostream>
#include <sstream>

board::board() {
    boardState_ = "     |     |     \n"
                  "     |     |     \n"
                  "     |     |     \n"
                  "-----------------\n"
                  "     |     |     \n"
                  "     |     |     \n"
                  "     |     |     \n"
                  "-----------------\n"
                  "     |     |     \n"
                  "     |     |     \n"
                  "     |     |     \n"; //start with an empty board
    xos_ = "abcdefghij"; //creating an empty xo list with dummy values (list will store which squares x's and o's are in)
    turnNumber_ = 1; //set the turn number so you start on turn one
}

void board::turn() {
    std::cout << "Turn " << turnNumber_ << ": ";
    char xo;
    if ((turnNumber_ % 2) == 1) xo = 'X'; //odd numbered turns are 'X' and even numbered turns are 'O'
    else xo = 'O';
    std::cout << xo << "'s move" << std::endl;
    
    int selection = 0;
    bool isValid = false;
    while (isValid == false) { //user selects a square which must be 1-9, otherwise this sequence loops
        std::cout << "Please select a square (1-9): ";

        //Converting string input into an integer
        std::string input;
        std::cin >> input;
        std::stringstream toint(input);
        toint >> selection; //now we have the user's input (their selected square) as an integer value

        std::cout << std::endl;

        if (selection < 1 || selection > 9 || xos_[selection] == 'X' || xos_[selection] == 'O') { //checks if the selected square is a valid one or not
            isValid = false;
            std::cout << "You must select a valid square, try again" << std::endl;
        }
        else isValid = true;
    }

    xos_[selection] = xo; //update xo list with the user's square selection
    switch (selection) { //updates the board the user sees with the new 'X' or 'O' selected
        case 1:
            boardState_[20] = xo;
            break;
        case 2:
            boardState_[26] = xo; 
            break;
        case 3:
            boardState_[32] = xo; 
            break;
        case 4:
            boardState_[92] = xo; 
            break;
        case 5:
            boardState_[98] = xo; 
            break;
        case 6:
            boardState_[104] = xo; 
            break;
        case 7:
            boardState_[164] = xo; 
            break;
        case 8:
            boardState_[170] = xo; 
            break;
        case 9:
            boardState_[176] = xo; 
            break;
    }
    ++turnNumber_; //updates turn value for next turn
}

bool board::isGameDone() {
    bool isFinished = true;
    if (xos_[1] == xos_[2] && xos_[1] == xos_[3]) { //checking top row
        std::cout << xos_[1] << " Wins!" << std::endl;
    }
    else if (xos_[4] == xos_[5] && xos_[4] == xos_[6]) { //checking middle row
        std::cout << xos_[4] << " Wins!" << std::endl;
    }
    else if (xos_[7] == xos_[8] && xos_[7] == xos_[9]) { //checking bottom row
        std::cout << xos_[7] << " Wins!" << std::endl;
    }
    else if (xos_[1] == xos_[4] && xos_[1] == xos_[7]) { //checking left column
        std::cout << xos_[1] << " Wins!" << std::endl;
    }
    else if (xos_[2] == xos_[5] && xos_[2] == xos_[8]) { //checking middle column
        std::cout << xos_[2] << " Wins!" << std::endl;
    }
    else if (xos_[3] == xos_[6] && xos_[3] == xos_[9]) { //checking right column
        std::cout << xos_[3] << " Wins!" << std::endl;
    }
    else if (xos_[1] == xos_[5] && xos_[1] == xos_[9]) { //checking top-left to bottom-right diagonal
        std::cout << xos_[1] << " Wins!" << std::endl;
    }
    else if (xos_[3] == xos_[5] && xos_[3] == xos_[7]) { //checking top-right to bottom-left diagonal
        std::cout << xos_[3] << " Wins!" << std::endl;
    }
    else if (turnNumber_ > 9) { //checking for tie
        std::cout << "The game is a tie." << std::endl;
    }
    else {
        isFinished = false;
    }
    return isFinished;
}