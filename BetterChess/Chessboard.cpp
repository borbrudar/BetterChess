#include "Chessboard.h"
#include <iostream>

void Chessboard::init()
{
	board.init("res/chessboard.jpg");

	pieces.push_back(Rook("res/chess-pieces.png", IntRect(853, 0, 213, 213)));
	pieces.push_back(Rook("res/chess-pieces.png", IntRect(853, 0, 213, 213)));

	pieces[0].currentPos = { 0,0 };
	pieces[1].currentPos = { 3,4 };
	pieces[0].updatePos();
	pieces[1].updatePos();

	t.loadFromFile("res/pus.jpg");
	pussy.setTexture(&t);
	pussy.setSize(Vector2f(880 / 2, 660 / 2));
}

void Chessboard::draw(RenderWindow& window)
{
	board.draw(window);

	for (int i = 0; i < pieces.size(); i++) pieces[i].draw(window);

	//window.draw(pussy);
}

void Chessboard::update(Event& event, Vector2i mousePos)
{
	if (event.type != Event::MouseButtonReleased) return;
	if (event.mouseButton.button != Mouse::Left) return;

	Vector2i clickedSquare = Vector2i(mousePos.x / squareLength,
		mousePos.y / squareLength);
	std::cout << clickedSquare.x << " " << clickedSquare.y << std::endl;
	pieces[0].update(pieces, mousePos);
	
}
