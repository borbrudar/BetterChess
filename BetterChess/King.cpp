#include "King.h"

King::King(color_type pieceColor)
{
	pieceType = piece::king;
	init(pieceColor);
}

bool King::isChecked(std::vector<std::unique_ptr<Piece>>& pieces, Vector2i newPos)
{
	check leftD = check::empty, rightD = check::empty;
	check vert = check::empty, hor = check::empty;
	//diagonals
	for (int i = newPos.x + 1, j = newPos.y + 1; i < squareNumber; i++, j++){
		if (leftD != check::empty) break;
		leftD = checkLine(i, j, pieces, 1);
	}
	for (int i = newPos.x - 1, j = newPos.y - 1; i >= 0; i--, j--) {
		if (leftD != check::empty) break;
		leftD = checkLine(i, j, pieces, 1);
	}
	for (int i = newPos.x - 1, j = newPos.y + 1; i >= 0; i--, j++) {
		if (rightD != check::empty) break;
		rightD = checkLine(i, j, pieces, 1);
	}
	for (int i = newPos.x + 1, j = newPos.y - 1; i < squareNumber; i++, j--) {
		if (rightD != check::empty) break;
		rightD = checkLine(i, j, pieces, 1);
	}

	//lines
	for (int i = newPos.x + 1; i < squareNumber; i++) {
		if (hor != check::empty) break;
		hor = checkLine(i, newPos.y, pieces);
	}
	for (int i = newPos.x - 1; i >= 0; i--) {
		if (hor != check::empty) break;
		hor = checkLine(i, newPos.y, pieces);
	}
	for (int i = newPos.y + 1; i < squareNumber; i++) {
		if (vert != check::empty) break;
		vert = checkLine(newPos.x, i, pieces);
	}
	for (int i = newPos.y - 1; i >= 0; i--) {
		if (vert != check::empty) break;
		vert = checkLine(newPos.x, i, pieces);
	}

	for (int i = 0; i < possibleMoves.size(); i++) {
		if (leftD == check::check) {
			if (helper(Vector2i(newPos.x + 1, newPos.y + 1), i)) break;
			if (helper(Vector2i(currentPos.x - 1, currentPos.y - 1), i)) break;
		}
		if (rightD == check::check) {
			if(helper(Vector2i(newPos.x + 1, newPos.y - 1), i)) break;
			if(helper(Vector2i(newPos.x - 1, newPos.y + 1), i)) break;
		}
		if (vert == check::check) {
			if(helper(Vector2i(newPos.x, newPos.y + 1), i)) break;
			if(helper(Vector2i(newPos.x, newPos.y - 1), i)) break;
		}
		if (hor == check::check) {
			if(helper(Vector2i(newPos.x + 1, newPos.y), i)) break;
			if(helper(Vector2i(newPos.x - 1, newPos.y), i)) break;
		}
	}

	bool knightCheck = false;
	//knights check
	int incx = 2, incy = 1;
	for (int incx = 2, incy = 1, count = 1; count < 9; count++) {
		//knight movement
		Vector2i tempVec = Vector2i(newPos.x + incx, newPos.y + incy);
		if (knightsCheck(pieces, tempVec)) {
			knightCheck = true;
			break;
		}
		//update iterators
		if (count == 4) std::swap(incx, incy);

		if (count % 2 == 0) incx = -incx;
		incy = -incy;
	}

	//kings
	for (int i = 0; i < pieces.size(); i++) {
		if (!(pieces[i]->pieceType == piece::king && pieces[i]->color != color)) continue;
		for (int j = 0; j < possibleMoves.size(); j++) {
			if (pieces[i]->possibleMoves[j].move == newPos) return true;
		}
	}

	//pawns
	for (int pi = 0; pi < pieces.size(); pi++) {
		if (pieces[pi]->pieceType != piece::pawn) continue;
		for (int i = 0; i < possibleMoves.size(); i++) {
			for (int j = 0; j < pieces[pi]->possibleMoves.size(); j++) {
				if (possibleMoves[i].move == pieces[pi]->possibleMoves[j].move) return true;
			}
		}
	}

	std::cout << "leftD: " << std::to_string((int)leftD) << std::endl;
	std::cout << "rightD: " << std::to_string((int)rightD) << std::endl;
	std::cout << "hor: " << std::to_string((int)hor) << std::endl;
	std::cout << "vert: " << std::to_string((int)vert) << std::endl;
	std::cout << "knight: " << std::to_string(knightCheck) << std::endl;

	return (leftD == check::check || rightD == check::check || 
		vert == check::check || hor == check::check || knightCheck);
}

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

check King::checkLine(int& posx, int& posy, std::vector<std::unique_ptr<Piece>>& pieces, bool diag)
{
	for (int j = 0; j < pieces.size(); j++) {
		if (pieces[j]->currentPos == Vector2i(posx, posy)) {
			if (pieces[j]->color == color) return check::not_check;
			//lines
			if (!diag) {
				if (pieces[j]->pieceType == piece::queen || pieces[j]->pieceType == piece::rook)
					return check::check;
			}
			//diagonals
			else if (pieces[j]->pieceType == piece::queen || pieces[j]->pieceType == piece::bishop) 
					return check::check;
			

			return check::not_check;
		}
	}

	return check::empty;
}

bool King::helper(Vector2i check, int &inc)
{
	if (possibleMoves[inc].move == check) {
		possibleMoves.erase(possibleMoves.begin() + inc);
	}
	return inc >= possibleMoves.size();
}

bool King::knightsCheck(std::vector<std::unique_ptr<Piece>>& pieces,Vector2i newPos)
{
	if (newPos.x < 0 || newPos.x >= squareNumber || newPos.y >= squareNumber || newPos.y < 0) 	return false;
	
	for (int i = 0; i < pieces.size(); i++) {
		if (pieces[i]->currentPos != newPos) continue;
		if (pieces[i]->pieceType != piece::knight) continue;
		if (pieces[i]->color == color) continue;
		return true;
	}

	return false;
}
