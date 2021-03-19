#include "Knight.h"

Knight::Knight(color_type pieceColor)
{
	pieceType = piece::knight;
	init(pieceColor);
}

void Knight::generatePossibleMoves(std::vector<std::unique_ptr<Piece >>& pieces)
{
	possibleMoves.clear();


	//check all combinations
	int incx = 2, incy = 1;

	for (int incx = 2, incy = 1, count = 1; count < 9;count++) {
		Vector2i tempVec = Vector2i(currentPos.x + incx, currentPos.y + incy);
		auto temp = grid->getByLocation(tempVec);
		move_type type;
		if (temp.color == color_type::none) type = move_type::move;
		else type = move_type::capture;

		if(temp.color != color)
			possibleMoves.push_back(moveType(tempVec, type));

		//update iterators
		if (count == 4) std::swap(incx, incy);

		if (count % 2 == 0) incx = -incx;
		incy = -incy;
	}


}
