#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>
#include "square.hpp"
#include <string>

struct board{
    struct square square[8][8];
    //settings
    std::string undo = "Off";
    std::string enforce = "On";
    std::string time_limit = "Off";

    void populateBoard();
    void printBoard();
    void play();
    void makeMove(std::string move, std::string color);
    bool removeOld(char piece, int newRow, int newColumn, std::string color, char oldPiece);
    void moveToNew(char column, char row, std::string piece, std::string color);
    std::string correctCase(char piece, std::string color);
    void settings();
    bool isGameOver();
};

void rules();

#endif