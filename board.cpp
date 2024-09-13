#include "board.h"

//////////////////////////////////////////////////////////////////////////////////////
Board::Board(int screen_width, int screen_height)
{
    this->m_screen_width = screen_width; 
    this->m_screen_height = screen_height; 
    this->m_tile_width = screen_height / 16; 
    this->m_player = Player::PLAYER_ONE; 
    this->m_option = Game_Option::SELECTING; 

    bool is_red = true; 

    // Iterate through the board, change color from red -> black 
    // or black -> red for each tile.
    for (int col = 0; col < 8; col++)
    {
        for (int row = 0; row < 8; row++)
        { 
            this->m_board[row][col].setColor((is_red) ? BEIGE : BROWN);
            is_red = !is_red;  
        }
        is_red = !is_red; 
    }

    // Set the tiles for specific pieces: 
    this->m_board[0][0].setPiece(Piece_Type::RED_PIECE); 
    this->m_board[2][0].setPiece(Piece_Type::RED_PIECE); 
    this->m_board[4][0].setPiece(Piece_Type::RED_PIECE);
    this->m_board[6][0].setPiece(Piece_Type::RED_PIECE);
    this->m_board[1][1].setPiece(Piece_Type::RED_PIECE);
    this->m_board[3][1].setPiece(Piece_Type::RED_PIECE);
    this->m_board[5][1].setPiece(Piece_Type::RED_PIECE);
    this->m_board[7][1].setPiece(Piece_Type::RED_PIECE);
    this->m_board[0][2].setPiece(Piece_Type::RED_PIECE);
    this->m_board[2][2].setPiece(Piece_Type::RED_PIECE);
    this->m_board[4][2].setPiece(Piece_Type::RED_PIECE);
    this->m_board[6][2].setPiece(Piece_Type::RED_PIECE);

    this->m_board[1][5].setPiece(Piece_Type::BLACK_PIECE); 
    this->m_board[3][5].setPiece(Piece_Type::BLACK_PIECE);
    this->m_board[5][5].setPiece(Piece_Type::BLACK_PIECE);
    this->m_board[7][5].setPiece(Piece_Type::BLACK_PIECE);
    this->m_board[0][6].setPiece(Piece_Type::BLACK_PIECE);
    this->m_board[2][6].setPiece(Piece_Type::BLACK_PIECE);
    this->m_board[4][6].setPiece(Piece_Type::BLACK_PIECE);
    this->m_board[6][6].setPiece(Piece_Type::BLACK_PIECE);
    this->m_board[1][7].setPiece(Piece_Type::BLACK_PIECE);
    this->m_board[3][7].setPiece(Piece_Type::BLACK_PIECE);
    this->m_board[5][7].setPiece(Piece_Type::BLACK_PIECE);
    this->m_board[7][7].setPiece(Piece_Type::BLACK_PIECE);
}

//////////////////////////////////////////////////////////////////////////////////////
void Board::drawBoard(int const screen_width, int const screen_height)
{
    // Loop through game board and draw tiles: 
    int tile_y_pos = 300; 
    for (int col = 0; col < 8; col++)
    {
        int tile_x_pos = 500; 
        for (int row = 0; row < 8; row++)
        {
            DrawRectangle(tile_x_pos, 
                          tile_y_pos, 
                          this->m_tile_width, 
                          this->m_tile_width, 
                          this->m_board[row][col].getColor()); 

            // Check for pieces: 
            if (this->m_board[row][col].getPieceSelected())
            {
                DrawCircle(tile_x_pos + this->m_tile_width/2,
                           tile_y_pos + this->m_tile_width/2,
                           this->m_tile_width/3,
                           YELLOW);
            }
            else if (this->m_board[row][col].getPiece() == Piece_Type::RED_PIECE)
            {
                DrawCircle(tile_x_pos + this->m_tile_width/2, 
                           tile_y_pos + this->m_tile_width/2, 
                           this->m_tile_width/3, 
                           RED);
            }
            else if (this->m_board[row][col].getPiece() == Piece_Type::BLACK_PIECE)
            {
                DrawCircle(tile_x_pos + this->m_tile_width/2,
                           tile_y_pos + this->m_tile_width/2, 
                           this->m_tile_width/3, 
                           BLACK); 
            }
            
            tile_x_pos += this->m_tile_width; 
        }
        tile_y_pos += this->m_tile_width; 
    }
}

//////////////////////////////////////////////////////////////////////////////////////
void Board::handleMouseClick(void)
{
    // Get mouse click: 
    int mouse_x = GetMouseX()/this->m_tile_width - 7; 
    int mouse_y = GetMouseY()/this->m_tile_width - 4;

    if (this->m_option == Game_Option::SELECTING)
    {
        selectPiece(mouse_x, mouse_y); 
    }
    else if (this->m_option == Game_Option::PLAYING)
    {
        playPiece(mouse_x, mouse_y); 
    }
}

//////////////////////////////////////////////////////////////////////////////////////
void Board::selectPiece(int mouse_x, int mouse_y)
{
    // Determine if the spot clicked has a valid piece to select: 
    if (this->m_board[mouse_x][mouse_y].getPiece() != Piece_Type::NO_PIECE)
    {
        // Find out if the right player clicked the right piece: 
        if ((this->m_board[mouse_x][mouse_y].getPiece() == Piece_Type::RED_PIECE) and
            (this->m_player == Player::PLAYER_ONE))
        {
            this->m_board[mouse_x][mouse_y].setPieceSelected(); 
            this->m_option = Game_Option::PLAYING; 
        }
    }
} 

//////////////////////////////////////////////////////////////////////////////////////
void Board::playPiece(int mouse_x, int mouse_y)
{
    // Determine if the selected piece was selected again: 
    if (this->m_board[mouse_x][mouse_y].getPieceSelected())
    {
        // Reset the piece: 
        if (this->m_player == Player::PLAYER_ONE)
        {
            this->m_board[mouse_x][mouse_y].setPieceSelected(); 
        }
        else if (this->m_player == Player::PLAYER_TWO)
        {
            this->m_board[mouse_x][mouse_y].setPieceSelected();
        }

        this->m_option = Game_Option::SELECTING; 
    }
} 
