//Header file for tic tac toe

#include <iostream>
#include <string>

#ifndef TTT_HEAD_
#define TTT_HEAD_

class board{
public:
    board(); //default constructor
    void printBoard() { std::cout << boardState_ << std::endl; }
    void turn();
    bool isGameDone();
    
private:
    std::string boardState_; //big string with the current state of the board - starts out empty from default constructor
    std::string xos_; //where the x's and o's are numerically
    int turnNumber_;
};

#endif