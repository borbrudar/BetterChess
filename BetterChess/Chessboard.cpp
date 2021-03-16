#include "Chessboard.h"

Chessboard::Chessboard()
{
	board.init("res/chessboard.jpg");
}

void Chessboard::draw(RenderWindow& window)
{
	board.draw(window);
}
