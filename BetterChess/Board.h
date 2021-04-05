#pragma once
#include "consts.h"
#include <vector>

struct Square {
	piece pieceType;
	color_type color;
};

class Board {
public:
	static Board* getInstance();
	Board(Board& other) = delete;
	void operator=(const Board &) = delete;
private:
	Board() = default;
	static Board* instance;

	std::vector<Square> board;
};

Board* Board::instance = nullptr;