#include "Board.h"

Board::Board()
{
	boardT.loadFromFile("res/chessboard.jpg");
	board.setTexture(boardT);
}

void Board::draw(RenderWindow& window)
{
	window.draw(board);
}
