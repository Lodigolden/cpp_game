#include "tile.h"
#include <iostream>

/*
A board for the checker game.
*/
class Board
{
public: 
    /*
    Default constructor for a board object.

    Args: 
        screen_width: Width of the screen (int)
        screen_height: Height of the screen (int)
    */
    Board(int screen_width, int screen_height);

    /*
    Draws the game board.
    */
    void drawBoard(int const screen_width, int const screen_height); 

    /*
    Handles a mouse click
    */
    void handleMouseClick(void); 

private: 
    Tile m_board[8][8];  // Checkers board
    int m_screen_width;  // Screen Width
    int m_screen_height; // Screen Height
    int m_tile_width;    // Tile Width
};