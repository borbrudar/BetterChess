#include "Board.h"
#include "Piece.h"

Board* Board::instance = nullptr;
Board* Board::getInstance()
{
	if (instance == nullptr) {
		instance = new Board();
	}
	return instance;
}

void Board::updateBoard(std::vector<std::unique_ptr<Piece>>& pieces)
{
	instance->squares.clear();
	for (int i = 0; i < squareNumber * squareNumber; i++) squares.push_back(Square());
	
	for (int i = 0; i < pieces.size(); i++) {
		Vector2i pPos = pieces[i]->currentPos;
		instance->squares[pPos.x + pPos.y * squareNumber] = Square(pieces[i]->pieceType, pieces[i]->color);
	}
}

std::vector<Vector2i> Board::getByPieceType(piece type, color_type color)
{
	std::vector<Vector2i> pieces;

	for (int i = 0; i < squares.size(); i++) {
		if (squares[i].color != color) continue;
		if (squares[i].pieceType != type) continue;
		pieces.push_back(Vector2i(i % squareNumber, i / squareNumber));
	}
	
	return pieces;
}

Square Board::getByLocation(Vector2i pos)
{
	if (pos.x + (pos.y * squareNumber) >= squares.size()) return Square(true);
	return squares[pos.x + (pos.y * squareNumber)];
}
