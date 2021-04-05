#include "Pawn.h"

Pawn::Pawn(color_type pieceColor)
{
	pieceType = piece::pawn;
	init(pieceColor);
	if (color == color_type::black) captureDirection = -captureDirection;
}

bool Pawn::isPromoted()
{
	if (color == color_type::white && currentPos.y == 0) return true;
	else if (color == color_type::black && currentPos.y == (squareNumber - 1)) return true;

	return false;
}

void Pawn::generatePossibleMoves(std::vector<std::unique_ptr<Piece>>& pieces)
{
	possibleMoves.clear();

	bool forward = true, two = true;
	bool left = false, right = false;
	bool en_left = false, en_right = false;


	for (int i = 0; i < pieces.size(); i++) {
	
	//basic
	if (grid->getByLocation(Vector2i(currentPos.x, currentPos.y + captureDirection)).pieceType != piece::empty) forward = false;
	if (grid->getByLocation(Vector2i(currentPos.x + 1, currentPos.y + captureDirection)).pieceType != piece::empty) right = true;
	if (grid->getByLocation(Vector2i(currentPos.x - 1, currentPos.y + captureDirection)).pieceType != piece::empty) left = true;

	//double first move
	if (!hasMoved && 
		grid->getByLocation(Vector2i(currentPos.x, currentPos.y + 2 * captureDirection)).pieceType != piece::empty) 
		two = false;

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
