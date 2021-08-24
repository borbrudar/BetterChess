#include "PromotionMenu.h"

void PromotionMenu::init(const char* path)
{
	texture.loadFromFile(path);
	sprite.setTexture(&texture);

	sprite.setSize(Vector2f(4 * SCR_WIDTH / squareNumber, SCR_HEIGHT / squareNumber));
	sprite.setPosition(2 * squareLength, 3.5 * squareLength);

	background.setFillColor(Color(255, 255, 255, 100));
	background.setSize(Vector2f(SCR_WIDTH, SCR_HEIGHT));
}

void PromotionMenu::setColor(color_type color)
{
	int col;
	color == color_type::white ? col = 0 : col = 1;
	IntRect texRect = IntRect(realSquareSize, col * realSquareSize, 4 * realSquareSize, realSquareSize);
	sprite.setTextureRect(texRect);
}

void PromotionMenu::draw(RenderWindow& window)
{
	if (!isShowed) return;
	
	window.draw(background);
	window.draw(sprite);
}

int PromotionMenu::update(Event event, Vector2i mousePos)
{
	if (!sprite.getGlobalBounds().contains(Vector2f(mousePos))) return -1;

	int localX = mousePos.x - sprite.getGlobalBounds().left;
	int piece = localX / squareLength;

	isShowed = false;
	return piece;

}
