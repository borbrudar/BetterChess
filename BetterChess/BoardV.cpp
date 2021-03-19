#include "BoardV.h"

void BoardV::init(const char* path)
{
	boardT.loadFromFile(path);
	board.setTexture(boardT);

	board.setPosition(300, 300);
	board.setOrigin(300,300);
}

void BoardV::draw(RenderWindow& window)
{
	window.draw(board);
}
