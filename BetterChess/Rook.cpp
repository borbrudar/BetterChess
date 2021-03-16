#include "Rook.h"

Rook::Rook(const char* path, IntRect texRect)
{
	pieceType = piece::rook;
	init(path, texRect);
}

void Rook::update(const std::vector<Piece> &board, Vector2i newPos)
{
	if (newPos.x < 0 || newPos.x > 7 || newPos.y < 0 || newPos.y > 7) return;
	
	if ((newPos.x != currentPos.x) && ( newPos.y != currentPos.y)) return;

	Piece boardPiece;
	for (int i = 0; i < board.size(); i++) {
		if (board[i].currentPos == newPos) {
			boardPiece = board[i];
			break;
		}
	}

	if (boardPiece.pieceType != piece::empty && boardPiece.color == color) return;


	currentPos = newPos;
	updatePos();
}
