#include <iostream>
#include <raylib.h>

#include "screen.h"
#include "board.h"

int main(void)
{
    // Screen settings: 
    int const screen_width{ 1600 };
    int const screen_height{ 1200 };

    InitWindow(screen_width, screen_height, "Checkers!");
    SetTargetFPS(60); 

    Board checkersBoard(screen_width, screen_height); 

    while (WindowShouldClose() == false)
    {
        BeginDrawing();

        // Draw the game board: 
        configureBackground(); 
        checkersBoard.drawBoard(screen_width, screen_height);

        // Handle clicking events: 
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            checkersBoard.handleMouseClick(); 
        } 

        EndDrawing(); 
    }

    CloseWindow(); 

    return 0; 
}
