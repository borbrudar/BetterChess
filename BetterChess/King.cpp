#include "King.h"

void King::generatePossibleMoves(std::vector<std::unique_ptr<Piece>>& pieces)
{
	possibleMoves.clear();
	//every direction
	for (int incx = -1, incy = -1, count = 0; count < 9; count++) {
		Vector2i tempVec = Vector2i(currentPos.x + incx, currentPos.y + incy);
		check_struct temp = checkIfNewPosOk(tempVec, pieces);
		if(temp.good)	possibleMoves.push_back(moveType(tempVec, temp.type));

		//update iterators
		if (incy == 1) {
			incy = -2;
			incx++;
		}		
		incy++;
	}

	//castling
	if (hasMoved) return;
	for (int i = 0; i < pieces.size(); i++) {
		if (pieces[i]->pieceType != piece::rook) continue;
		if (pieces[i]->color != color) continue;
		if (pieces[i]->hasMoved) continue;

		int incx = -2;
		if (pieces[i]->currentPos.x > currentPos.x) {
			incx = 2;
			for (int j = 0; j < pieces.size(); j++){
				if (pieces[j]->currentPos == Vector2i(currentPos.x + 1, currentPos.y)) return;
				if (pieces[j]->currentPos == Vector2i(currentPos.x + 2, currentPos.y)) return;
			}
		}
		else {
			for (int j = 0; j < pieces.size(); j++) {
				if (pieces[j]->currentPos == Vector2i(currentPos.x - 1, currentPos.y)) return;
				if (pieces[j]->currentPos == Vector2i(currentPos.x - 2, currentPos.y)) return;
				if (pieces[j]->currentPos == Vector2i(currentPos.x - 3, currentPos.y)) return;
			}
		}

		possibleMoves.push_back(moveType(Vector2i(currentPos.x + incx, currentPos.y), move_type::castling));


	}

}

King::King(color_type pieceColor)
{
	pieceType = piece::king;
	init(pieceColor);
}

move_type King::update(std::vector<std::unique_ptr<Piece>>& pieces, Vector2i newPos)
{
	generatePossibleMoves(pieces);
	return checkNewPos(newPos);
}
