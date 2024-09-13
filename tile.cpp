#include "tile.h"

//////////////////////////////////////////////////////////////////////////////////////
Tile::Tile(void)
{
    this->p_color = BLACK; 
    this->p_piece = NO_PIECE; 
    this->p_is_selected = false; 
}

//////////////////////////////////////////////////////////////////////////////////////
void Tile::setColor(Color col)
{
    this->p_color = col; 
}

//////////////////////////////////////////////////////////////////////////////////////
void Tile::setPiece(Piece tile_piece)
{
    this->p_piece = tile_piece; 
}

//////////////////////////////////////////////////////////////////////////////////////
void Tile::setPieceSelected(void)
{
    this->p_is_selected = !this->p_is_selected; 
}

//////////////////////////////////////////////////////////////////////////////////////
Color Tile::getColor(void)
{
    return this->p_color; 
}

//////////////////////////////////////////////////////////////////////////////////////
Piece Tile::getPiece(void)
{
    return this->p_piece; 
} 

//////////////////////////////////////////////////////////////////////////////////////
bool Tile::getPieceSelected(void)
{
    return this->p_is_selected; 
}