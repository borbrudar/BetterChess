#pragma once
#include <SFML/Graphics.hpp>
#include "consts.h"
using namespace sf;

class PromotionMenu {
public:
	void init(const char* path);
	void setColor(color_type color);
	void draw(RenderWindow& window);
	int update(Event event, Vector2i mousePos);
	
	bool isShowed = false;
private:
	RectangleShape sprite, background;
	Texture texture;
};