#include "Bishop.h"

Bishop::Bishop(color_type pieceColor)
{
	pieceType = piece::bishop;
	init(pieceColor);
}

void Bishop::generatePossibleMoves(std::vector<std::unique_ptr<Piece>>& pieces)
{
	possibleMoves.clear();

	for (int i = currentPos.x + 1, j = currentPos.y + 1; i < squareNumber; i++,j++) 
		if (checkLine(i, j, pieces)) break;
	for (int i = currentPos.x - 1, j = currentPos.y + 1; i >= 0; i--, j++)
		if (checkLine(i, j, pieces)) break;
	for (int i = currentPos.x + 1, j = currentPos.y - 1; i < squareNumber; i++,j--)
		if (checkLine(i, j, pieces)) break;
	for (int i = currentPos.x - 1, j = currentPos.y - 1; i >= 0; i--,j--) 	
		if (checkLine(i, j, pieces)) break;
}