#include "Chessboard.h"
#include <iostream>

void Chessboard::init()
{
	board.init("res/chessboard.jpg");
	Piece::loadTexture(path);

	pieces.resize(7);
	pieces[0] = std::make_unique<Rook>(color_type::white);
	pieces[1] = std::make_unique<Knight>(color_type::white);
	pieces[2] = std::make_unique<Bishop>(color_type::black);
	pieces[3] = std::make_unique<Queen>(color_type::white);
	pieces[4] = std::make_unique<King>(color_type::black);
	pieces[5] = std::make_unique<Pawn>(color_type::black);
	pieces[6] = std::make_unique<Pawn>(color_type::white);

	pieces[0]->currentPos = { 0,0 };
	pieces[1]->currentPos = { 3,4 };
	pieces[2]->currentPos = { 6,0 };
	pieces[3]->currentPos = { 1,6 };
	pieces[4]->currentPos = { 5,4 };
	pieces[5]->currentPos = { 7,1 };
	pieces[6]->currentPos = { 6,6 };

	menu.init(path);
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
			int promoted = menu.update(event, mousePos);
			checkPromotion(promoted);
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

	//promotion
	if (pieces[selectedPiece]->isPromoted()) {
		menu.isShowed = true;
		menu.setColor(pieces[selectedPiece]->color);
	}
	switch (type) {
	case move_type::capture:
		for (auto i = 0; i < pieces.size(); i++) {
			if (i == selectedPiece) continue;
			if (pieces[i]->currentPos == pieces[selectedPiece]->currentPos) {
				pieces.erase(pieces.begin() + i);
				break;
			}
		}
		break;
	case move_type::passant:
		for (auto i = 0; i < pieces.size(); i++) {
			if (pieces[i]->currentPos == Vector2i(pieces[selectedPiece]->currentPos.x,
				(pieces[selectedPiece]->currentPos.y - pieces[selectedPiece]->captureDirection))) {
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

void Chessboard::checkPromotion(int promoted)
{
	if (promoted != -1) {
		for (int i = 0; i < pieces.size(); i++) {
			if (pieces[i]->isPromoted()) {
				Vector2i temp = pieces[i]->currentPos;
				color_type tempCol = pieces[i]->color;
				switch (promoted) {
				case 0:
					pieces[i] = std::make_unique<Queen>(tempCol); break;
				case 1:
					pieces[i] = std::make_unique<Bishop>(tempCol); break;
				case 2:
					pieces[i] = std::make_unique<Knight>(tempCol); break;
				case 3:
					pieces[i] = std::make_unique<Rook>(tempCol); break;
				}
				pieces[i]->currentPos = temp;
				break;
			}

		}
	}
}
