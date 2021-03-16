#include "Chessboard.h"
#include <iostream>

Chessboard::Chessboard()
{
	board.init("res/chessboard.jpg");
	rook.init("res/chess-pieces.png", IntRect(853,0,213,213));

	chessboard.resize(64);
	chessboard[0] = piece::rook;
}

void Chessboard::draw(RenderWindow& window)
{
	board.draw(window);
	rook.draw(window);
}

void Chessboard::update(Event& event, Vector2i mousePos)
{
	if (event.type != Event::MouseButtonReleased) return;
	if (event.mouseButton.button != Mouse::Left) return;

	float squareNumber = 8;
	float length = SCR_WIDTH / squareNumber;
	Vector2i clickedSquare = Vector2i(mousePos.x / length,
		mousePos.y /length);
	std::cout << clickedSquare.x << " " << clickedSquare.y << std::endl;
	rook.update(chessboard, clickedSquare);
}
