#include "Piece.h"

void Piece::init(const char* path, IntRect texRect)
{
	texture.loadFromFile(path);
	sprite.setTexture(&texture);
	sprite.setTextureRect(texRect);

	int squareNumber = 8;
	sprite.setSize(Vector2f(SCR_WIDTH / squareNumber, SCR_HEIGHT / squareNumber));
}

void Piece::draw(RenderWindow& window)
{
	window.draw(sprite);
}
