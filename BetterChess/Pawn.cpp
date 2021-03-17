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

void Pawn::generatePossibleMoves(std::vector<Piece*>& pieces)
{
	possibleMoves.clear();

	bool forward = true, two = true;
	bool left = false, right = false;


	for (int i = 0; i < pieces.size(); i++) {
	//basic
	if (pieces[i]->currentPos == Vector2i(currentPos.x, currentPos.y + captureDirection)) forward = false;
	if (pieces[i]->currentPos == Vector2i(currentPos.x + 1, currentPos.y + captureDirection)) right = true;
	if (pieces[i]->currentPos == Vector2i(currentPos.x - 1, currentPos.y + captureDirection)) left = true;

	//double first move
	if (!hasMoved) {
		if (pieces[i]->currentPos == Vector2i(currentPos.x, currentPos.y + 2 * captureDirection)) two = false;
	}

	}
	//basic
	if (forward) possibleMoves.push_back(moveType(Vector2i(currentPos.x, currentPos.y + captureDirection), move_type::move));
	if (right) possibleMoves.push_back(moveType(Vector2i(currentPos.x + 1, currentPos.y + captureDirection), move_type::capture));
	if (left) possibleMoves.push_back(moveType(Vector2i(currentPos.x - 1, currentPos.y + captureDirection), move_type::capture));
	if(two && !hasMoved) possibleMoves.push_back(moveType(Vector2i(currentPos.x, currentPos.y + 2* captureDirection), move_type::move));


	if (forward || left || right || two) hasMoved = true;
}
