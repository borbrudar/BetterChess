#include "Queen.h"

Queen::Queen(const char* path, IntRect texRect)
{
	pieceType = piece::queen;
	init(path, texRect);
}

void Queen::generatePossibleMoves(std::vector<Piece*>& pieces)
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

move_type Queen::update(std::vector<Piece*>& pieces, Vector2i newPos)
{
	generatePossibleMoves(pieces);
	return checkNewPos(newPos);
}
