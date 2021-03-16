#include "Piece.h"

void Piece::init(const char* path, IntRect texRect)
{
	texture.loadFromFile(path);
	sprite.setTexture(texture);
	sprite.setTextureRect(texRect);
}

void Piece::draw(RenderWindow& window)
{
	window.draw(sprite);
}
