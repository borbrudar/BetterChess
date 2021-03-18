#include "Bishop.h"

Bishop::Bishop(const char* path, IntRect texRect)
{
	pieceType = piece::bishop;
	init(path, texRect);
}

void Bishop::generatePossibleMoves(std::vector<Piece*>& pieces)
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

move_type Bishop::update(std::vector<Piece*>& pieces, Vector2i newPos)
{
	generatePossibleMoves(pieces);
	return checkNewPos(newPos);
}

