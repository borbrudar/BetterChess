#include "PromotionMenu.h"

void PromotionMenu::init(const char* path, IntRect texRect)
{
	texture.loadFromFile(path);
	sprite.setTexture(&texture);
	sprite.setTextureRect(texRect);
	sprite.setSize(Vector2f(4 * SCR_WIDTH / squareNumber, SCR_HEIGHT / squareNumber));
	sprite.setPosition(2 * squareLength, 3.5 * squareLength);

	background.setFillColor(Color(255, 255, 255, 100));
	background.setSize(Vector2f(SCR_WIDTH, SCR_HEIGHT));

}

void PromotionMenu::draw(RenderWindow& window)
{
	if (!isShowed) return;
	
	window.draw(background);
	window.draw(sprite);
}

piece PromotionMenu::update(Event event, Vector2i mousePos)
{
	if (!sprite.getGlobalBounds().contains(Vector2f(mousePos))) return piece::empty;

	int localX = mousePos.x - sprite.getGlobalBounds().left;
	int piece = localX / squareLength;

	isShowed = false;
	switch (piece) {
	case 0:return piece::queen; break;
	case 1:return piece::bishop; break;
	case 2:return piece::knight; break;
	case 3:return piece::rook; break;
	}

}
