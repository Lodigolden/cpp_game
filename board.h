#include <iostream>
#include <memory>

#include "tile.h"

enum Player
{
    PLAYER_ONE,
    PLAYER_TWO
};

enum Game_Option
{
    SELECTING,
    PLAYING
};

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

    /*
    Selects a piece

    Args: 
        mouse_x: X-position (int)
        mouse_y: Y-position (int)
    */
    void selectPiece(int mouse_x, int mouse_y); 

    /*
    Determines how to play a piece

    Args: 
        mouse_x: X-position (int)
        mouse_y: Y-position (int)
    */
   void playPiece(int mouse_x, int mouse_y); 

private: 
    Tile m_board[8][8];     // Checkers board
    int m_screen_width;     // Screen Width
    int m_screen_height;    // Screen Height
    int m_tile_width;       // Tile Width
    Player m_player;        // Current Player
    Game_Option m_option;   // Whether the player is selecting or 
                            // moving a piece
};