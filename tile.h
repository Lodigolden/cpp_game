#include <raylib.h>

/*
An enum for if a tile has a piece
*/
enum Piece
{
    NO_PIECE,
    RED_PIECE,
    BLACK_PIECE,
    SELECTED_PIECE
};

/*
A tile class for the game board.
*/
class Tile
{
public: 
    /*
    Default constructor for a tile object. 
    */
    Tile(void); 

    /*
    Sets the color of the tile.

    Args: 
        col: Tile color (Color)
    */
    void setColor(Color col);

    /*
    Sets the piece on the tile.

    Args: 
        tile_piece: Piece on the tile (Piece)
    */
    void setPiece(Piece tile_piece); 

    /*
    Toggles if the piece is selected.
    */
    void setPieceSelected(void); 

    /*
    Gets the color of the tile.

    Returns: 
        The tile color (Color)
    */
    Color getColor(void); 

    /*
    Gets the piece on the tile.

    Returns: 
        The tile piece (Piece)
    */
    Piece getPiece(void); 

    /*
    Gets if the piece is selected. 

    Returns: 
        Whether the piece is selected (bool)
    */
   bool getPieceSelected(void); 

private: 
    Color p_color;      // Color of the tile
    Piece p_piece;      // Piece on the tile
    bool p_is_selected; // If the piece is selected
};