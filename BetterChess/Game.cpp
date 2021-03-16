#include "Game.h"

Game::Game()
{
	window.create(VideoMode(SCR_WIDTH, SCR_HEIGHT), "Chess");
	board.init("res/chessboard.jpg");
}

void Game::run()
{
	while (window.isOpen()) {
		draw();
		update();
	}
}

void Game::draw()
{
	window.clear(Color(160, 160, 160));

	board.draw(window);

	window.display();
}

void Game::update()
{
	while (window.pollEvent(event)) {
		if (event.type == Event::Closed) window.close();
	}
}
