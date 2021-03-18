#include "Chessboard.h"
#include <iostream>

void Chessboard::init()
{
	board.init("res/chessboard.jpg");
	Piece::loadTexture(path);

	pieces.resize(7);
	pieces[0] = std::make_unique<Rook>(IntRect(853, 0, 213, 213));
	pieces[1] = std::make_unique<Knight>(IntRect(640, 0, 213, 213));
	pieces[2] = std::make_unique<Bishop>(IntRect(427, 214, 213, 213));
	pieces[3] = std::make_unique<Queen>(IntRect(213, 0, 213, 213));
	pieces[4] = std::make_unique<King>(IntRect(0, 213, 213, 213));
	pieces[5] = std::make_unique<Pawn>(IntRect(1066, 213, 213, 213));
	pieces[6] = std::make_unique<Pawn>(IntRect(1066, 0, 213, 213));

	pieces[0]->currentPos = { 0,0 };
	pieces[1]->currentPos = { 3,4 };
	pieces[2]->currentPos = { 6,0 };
	pieces[3]->currentPos = { 1,6 };
	pieces[4]->currentPos = { 5,4 };
	pieces[5]->currentPos = { 7,1 };
	pieces[6]->currentPos = { 6,6 };

	menu.init(path, IntRect(213, 0, 4 * 213, 213));
}

void Chessboard::draw(RenderWindow& window)
{
	board.draw(window);

	for (int i = 0; i < pieces.size(); i++) pieces[i]->draw(window);

	menu.draw(window);
}

void Chessboard::update(Event& event, Vector2i mousePos)
{
	if (event.type != Event::MouseButtonReleased) return;
	if (event.mouseButton.button != Mouse::Left) return;

	if (menu.isShowed) {
		auto promoted = menu.update(event, mousePos); if (promoted != piece::empty) {
			for (int i = 0; i < pieces.size(); i++) {
				if (pieces[i]->isPromoted()) {
					Vector2i temp = pieces[i]->currentPos;
					switch (promoted) {
					case piece::queen:
						pieces[i] = std::make_unique<Queen>(IntRect(213, 0, 213, 213)); break;
					case piece::bishop:
						pieces[i] = std::make_unique<Bishop>(IntRect(427, 0, 213, 213)); break;
					case piece::knight:
						pieces[i] = std::make_unique<Knight>(IntRect(640, 0, 213, 213)); break;
					case piece::rook:
						pieces[i] = std::make_unique<Rook>(IntRect(853, 0, 213, 213)); break;
					}
					pieces[i]->currentPos = temp;
					break;
				}

			}
		}
	}
	else movePiece(mousePos);

	
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
	auto type = pieces[selectedPiece]->update(pieces, clickedSquare);
	switch (type) {
	case move_type::capture:
		for (auto i = 0; i < pieces.size(); i++) {
			if (i == selectedPiece) continue;
			if (pieces[i]->currentPos == pieces[selectedPiece]->currentPos) {
				if (pieces[selectedPiece]->isPromoted()) menu.isShowed = true;
				pieces.erase(pieces.begin() + i);
				break;
			}
		}
		break;
	case move_type::passant:
		for (auto i = 0; i < pieces.size(); i++) {
			if (pieces[i]->currentPos == Vector2i(pieces[selectedPiece]->currentPos.x,
				(pieces[selectedPiece]->currentPos.y - pieces[selectedPiece]->captureDirection))) {
				if (pieces[selectedPiece]->isPromoted()) menu.isShowed = true;
				pieces.erase(pieces.begin() + i);
				break;
			}
		}
		break;
	}
	

	isPieceSelected = false;
	if (!(type == move_type::twice || type == move_type::none)) {
		for (int i = 0; i < pieces.size(); i++) {
			pieces[i]->resetPassant();
		}
	}

}