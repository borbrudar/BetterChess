#pragma once
#include <SFML/Graphics.hpp>
#include "consts.h"
using namespace sf;

class PromotionMenu {
public:
	void init(const char* path, IntRect texRect);
	void draw(RenderWindow& window);
	piece update(Event event, Vector2i mousePos);
	
	bool isShowed = false;
	RectangleShape sprite, background;
	Texture texture;
};