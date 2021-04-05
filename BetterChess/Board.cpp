#include "Board.h"

Board* Board::getInstance()
{
	if (instance == nullptr) {
		instance = new Board();
	}
	return instance;
}
