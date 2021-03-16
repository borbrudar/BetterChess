#include "Game.h"

Game::Game()
{
	window.create(VideoMode(SCR_WIDTH, SCR_HEIGHT), "Chess");
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

	chessboard.draw(window);

	window.display();
}

void Game::update()
{
	while (window.pollEvent(event)) {
		if (event.type == Event::Closed) window.close();
	}
}
