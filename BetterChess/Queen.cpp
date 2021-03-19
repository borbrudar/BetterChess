#include "Queen.h"

Queen::Queen(color_type pieceColor)
{
	pieceType = piece::queen;
	init(pieceColor);
}

void Queen::generatePossibleMoves(std::vector< std::unique_ptr<Piece>>& pieces)
{
	//bishop
	for (int i = currentPos.x + 1, j = currentPos.y + 1; i < squareNumber; i++, j++) 
		if (checkLine(i, j, pieces)) break;
	for (int i = currentPos.x - 1, j = currentPos.y + 1; i >= 0; i--, j++) 
		if (checkLine(i, j, pieces)) break;
	for (int i = currentPos.x + 1, j = currentPos.y - 1; i < squareNumber; i++, j--) 
		if (checkLine(i, j, pieces)) break;
	for (int i = currentPos.x - 1, j = currentPos.y - 1; i >= 0; i--, j--) 
		if (checkLine(i, j, pieces)) break;
	
	//rook
	for (int i = currentPos.x + 1; i < squareNumber; i++)
		if (checkLine(i, currentPos.y, pieces)) break;
	for (int i = currentPos.x - 1; i >= 0; i--) 
		if (checkLine(i, currentPos.y, pieces)) break;
	for (int i = currentPos.y + 1; i < squareNumber; i++) 
		if (checkLine(currentPos.x, i, pieces)) break;
	for (int i = currentPos.y - 1; i >= 0; i--) 
		if (checkLine(currentPos.x, i, pieces)) break;
}
