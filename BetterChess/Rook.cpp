#include "Rook.h"

Rook::Rook()
{
	pieceType = piece::rook;
}

void Rook::update(const std::vector<piece> board, Vector2i newPos)
{
	if (newPos.x < 0 || newPos.x > 7 || newPos.y < 0 || newPos.y > 7) return;
	if ((newPos.x != currentPos.x) && ( newPos.y != currentPos.y)) return;

	currentPos = newPos;
	updatePos();
}
