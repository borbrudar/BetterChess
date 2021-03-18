#include "Bishop.h"

Bishop::Bishop(IntRect texRect)
{
	pieceType = piece::bishop;
	init(texRect);
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

move_type Bishop::update(std::vector<std::unique_ptr<Piece>>& pieces, Vector2i newPos)
{
	generatePossibleMoves(pieces);
	return checkNewPos(newPos);
}

