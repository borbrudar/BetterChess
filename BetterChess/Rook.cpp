#include "Rook.h"
#include <iostream>

Rook::Rook(const char* path, IntRect texRect)
{
	pieceType = piece::rook;
	init(path, texRect);
}

void Rook::generatePossibleMoves(std::vector<Piece*>& pieces)
{
	possibleMoves.clear();
	for (int i = currentPos.x + 1; i < squareNumber; i++) {
		if (checkLine(i, currentPos.y, pieces)) break;
	}
	for (int i = currentPos.x - 1; i >= 0; i--) {
		if (checkLine(i, currentPos.y, pieces)) break;
	}
	for (int i = currentPos.y + 1; i < squareNumber; i++) {
		if (checkLine(currentPos.x, i, pieces)) break;
	}
	for (int i = currentPos.y - 1; i >= 0; i--) {
		if (checkLine(currentPos.x, i, pieces)) break;
	}
}

move_type Rook::update(std::vector<Piece*>& pieces, Vector2i newPos)
{	
	generatePossibleMoves(pieces);
	return checkNewPos(newPos);
}

bool Rook::checkLine(int& posx, int& posy, std::vector<Piece*> pieces)
{
	bool addLine = true, addMove = true;
	for (int j = 0; j < pieces.size(); j++) {
		if (pieces[j]->currentPos == Vector2i(posx, posy)) { 
			addLine = false;

			if (pieces[j]->color == color) addMove = false;
			else addMove = true;
		}
	}
	if (addMove) {
		move_type addType;
		if (!addLine) addType = move_type::capture;
		else addType = move_type::move;

		possibleMoves.push_back(moveType(Vector2i(posx, posy), addType));
	}

	return !addLine;
}
