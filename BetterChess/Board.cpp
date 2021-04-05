#include "Board.h"

void Board::init(const char* path)
{
	boardT.loadFromFile(path);
	board.setTexture(boardT);

	board.setPosition(300, 300);
	board.setOrigin(300,300);
}

void Board::draw(RenderWindow& window)
{
	window.draw(board);
}

void Board::flip()
{
	board.rotate(rotation);
	rotation = -rotation;
}
