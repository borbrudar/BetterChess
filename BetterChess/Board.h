#pragma once
#include "consts.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include "Square.h"
#include "Exception.h"

class Piece;
using namespace sf;
class Board {
public:
	static Board* getInstance();
	Board(Board& other) = delete;
	void operator=(const Board &) = delete;
	void updateBoard(std::vector<std::unique_ptr<Piece>>& pieces);
	std::vector<Vector2i> getByPieceType(piece type, color_type color);
	Square getByLocation(Vector2i pos);
private:
	Board() = default;
	static Board* instance;

	std::vector<Square> squares;
};
