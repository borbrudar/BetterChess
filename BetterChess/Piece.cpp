#include "Piece.h"

Piece::Piece(const char* path, IntRect texRect)
{
	init(path, texRect);
}

void Piece::init(const char* path, IntRect texRect)
{
	texture.loadFromFile(path);
	sprite.setTexture(&texture);
	sprite.setTextureRect(texRect);
	sprite.setSize(Vector2f(SCR_WIDTH / squareNumber, SCR_HEIGHT / squareNumber));

	updatePos();
	if (texRect.top < (texture.getSize().y / 2))  color = color_type::white;
	else color = color_type::black;
}

void Piece::draw(RenderWindow& window)
{
	window.draw(sprite);
}

move_type Piece::checkNewPos(Vector2i newPos)
{
	for (int i = 0; i < possibleMoves.size(); i++) {
		if (possibleMoves[i].move == newPos) {
			currentPos = newPos;
			updatePos();
			return possibleMoves[i].type;
		}
	}

	return move_type::none;
}

void Piece::updatePos()
{
	sprite.setPosition(currentPos.x * squareLength, currentPos.y * squareLength);
}
