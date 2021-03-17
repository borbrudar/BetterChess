#include "Chessboard.h"
#include <iostream>

void Chessboard::init()
{
	board.init("res/chessboard.jpg");

	pieces.resize(7);
	const char* path = "res/chess-pieces.png";
	pieces[0] = new Rook(path, IntRect(853, 0, 213, 213));
	pieces[1] = new Rook(path, IntRect(853, 214, 213, 213));
	pieces[2] = new Knight(path, IntRect(640, 0, 213, 213));
	pieces[3] = new Bishop(path, IntRect(427, 214, 213, 213));
	pieces[4] = new Queen(path, IntRect(213, 0, 213, 213));
	pieces[5] = new King(path, IntRect(0, 213, 213, 213));
	pieces[6] = new Pawn(path, IntRect(1066, 0, 213, 213));


	pieces[0]->currentPos = { 0,0 };
	pieces[1]->currentPos = { 6,6 };
	pieces[2]->currentPos = { 3,4 };
	pieces[3]->currentPos = { 6,0 };
	pieces[4]->currentPos = { 1,6 };
	pieces[5]->currentPos = { 5,4 };
	pieces[6]->currentPos = { 7,6 };
	for(int i = 0; i < pieces.size();i++)
		pieces[i]->updatePos();

}

void Chessboard::draw(RenderWindow& window)
{
	board.draw(window);

	for (int i = 0; i < pieces.size(); i++) pieces[i]->draw(window);

}

void Chessboard::update(Event& event, Vector2i mousePos)
{
	if (event.type != Event::MouseButtonReleased) return;
	if (event.mouseButton.button != Mouse::Left) return;

	movePiece(mousePos);
}

void Chessboard::movePiece(Vector2i mousePos)
{
	Vector2i clickedSquare = Vector2i(mousePos.x / squareLength,
		mousePos.y / squareLength);
	std::cout << clickedSquare.x << " " << clickedSquare.y << std::endl;

	//check if the selected square has a piece on it
	if (!isPieceSelected) {
		for (int i = 0; i < pieces.size(); i++) {
			if (pieces[i]->currentPos == clickedSquare) {
				selectedPiece = i;
				isPieceSelected = true;
				return;
			}
		}
		return;
	}

	//on the second pass check for movement
	if (pieces[selectedPiece]->update(pieces, clickedSquare) == move_type::capture) {
		for (auto i = 0; i < pieces.size(); i++) {
			if (i == selectedPiece) continue;
			if (pieces[i]->currentPos == pieces[selectedPiece]->currentPos) {
				pieces.erase(pieces.begin() + i);
				break;
			}
		}
	}

	isPieceSelected = false;
}
