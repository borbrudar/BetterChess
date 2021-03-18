#include "Knight.h"

Knight::Knight( IntRect texRect)
{
	pieceType = piece::knight;
	init(texRect);
}

move_type Knight::update(std::vector<std::unique_ptr<Piece>>& pieces, Vector2i newPos)
{
	generatePossibleMoves(pieces);
	return checkNewPos(newPos);
}

void Knight::generatePossibleMoves(std::vector<std::unique_ptr<Piece >>& pieces)
{
	possibleMoves.clear();

	//check all combinations
	int incx = 2, incy = 1;

	for (int incx = 2, incy = 1, count = 1; count < 9;count++) {
		//knight movement
		Vector2i tempVec = Vector2i(currentPos.x + incx, currentPos.y + incy);
		check_struct temp = checkIfNewPosOk(tempVec, pieces);
		if (temp.good)
			possibleMoves.push_back(moveType(tempVec, temp.type));

		//update iterators
		if (count == 4) std::swap(incx, incy);

		if (count % 2 == 0) incx = -incx;
		incy = -incy;
	}


}
