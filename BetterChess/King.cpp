#include "King.h"

void King::generatePossibleMoves(std::vector<std::unique_ptr<Piece>>& pieces)
{
	//every direction
	for (int incx = -1, incy = -1, count = 0; count < 9; count++) {
		Vector2i tempVec = Vector2i(currentPos.x + incx, currentPos.y + incy);
		check_struct temp = checkIfNewPosOk(tempVec, pieces);
		if(temp.good)	possibleMoves.push_back(moveType(tempVec, temp.type));

		//update iterators
		if (incy == 1) {
			incy = -1;
			incx++;
		}		
		incy++;

	}
}

King::King(Vector2i square)
{
	pieceType = piece::king;
	init(square);
}

move_type King::update(std::vector<std::unique_ptr<Piece>>& pieces, Vector2i newPos)
{
	generatePossibleMoves(pieces);
	return checkNewPos(newPos);
}
