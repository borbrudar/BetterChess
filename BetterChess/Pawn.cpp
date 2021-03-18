#include "Pawn.h"

Pawn::Pawn(const char* path, IntRect texRect)
{
	pieceType = piece::pawn;
	init(path, texRect);
	if (color == color_type::black) captureDirection = -captureDirection;
}

move_type Pawn::update(std::vector<Piece*>& pieces, Vector2i newPos)
{
	generatePossibleMoves(pieces);
	return checkNewPos(newPos);
}

bool Pawn::isPromoted()
{
	if (color == color_type::white && currentPos.y == 0) return true;
	else if (color == color_type::black && currentPos.y == squareNumber) return true;

	return false;
}

void Pawn::generatePossibleMoves(std::vector<Piece*>& pieces)
{
	possibleMoves.clear();

	bool forward = true, two = true;
	bool left = false, right = false;
	bool en_left = false, en_right = false;


	for (int i = 0; i < pieces.size(); i++) {
	//basic
	if (pieces[i]->currentPos == Vector2i(currentPos.x, currentPos.y + captureDirection)) forward = false;
	if (pieces[i]->currentPos == Vector2i(currentPos.x + 1, currentPos.y + captureDirection)) right = true;
	if (pieces[i]->currentPos == Vector2i(currentPos.x - 1, currentPos.y + captureDirection)) left = true;

	//double first move
	if (!hasMoved) {
		if (pieces[i]->currentPos == Vector2i(currentPos.x, currentPos.y + 2 * captureDirection)) two = false;
	}

	//en passant
	if (pieces[i]->currentPos == Vector2i(currentPos.x + 1, currentPos.y) && pieces[i]->enPassant)  en_right = true;
	if (pieces[i]->currentPos == Vector2i(currentPos.x - 1, currentPos.y) && pieces[i]->enPassant)  en_left = true;
	}
	//check
	if (forward) possibleMoves.push_back(moveType(Vector2i(currentPos.x, currentPos.y + captureDirection), move_type::move));
	if (right) possibleMoves.push_back(moveType(Vector2i(currentPos.x + 1, currentPos.y + captureDirection), move_type::capture));
	if (left) possibleMoves.push_back(moveType(Vector2i(currentPos.x - 1, currentPos.y + captureDirection), move_type::capture));
	if (two && !hasMoved) {
		possibleMoves.push_back(moveType(Vector2i(currentPos.x, currentPos.y + 2 * captureDirection), move_type::twice));
		enPassant = true;
	}
	
	if (en_right)  possibleMoves.push_back(moveType(Vector2i(currentPos.x + 1, currentPos.y + captureDirection), move_type::passant));
	if (en_left)  possibleMoves.push_back(moveType(Vector2i(currentPos.x - 1, currentPos.y + captureDirection), move_type::passant));

}
