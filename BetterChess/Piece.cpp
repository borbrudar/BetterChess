#include "Piece.h"

Piece::Piece(const char* path, IntRect texRect)
{
	init(path, texRect);
}

void Piece::init(const char* path, IntRect texRect)
{
	texture.loadFromFile(path);
	sprite.setTexture(&texture);
	sprite.setTextureRect(texRect);
	sprite.setSize(Vector2f(SCR_WIDTH / squareNumber, SCR_HEIGHT / squareNumber));

	updatePos();
	if (texRect.top < (texture.getSize().y / 2))  color = color_type::white;
	else color = color_type::black;
}

void Piece::draw(RenderWindow& window)
{
	window.draw(sprite);
}

move_type Piece::checkNewPos(Vector2i newPos)
{
	for (int i = 0; i < possibleMoves.size(); i++) {
		if (possibleMoves[i].move == newPos) {
			currentPos = newPos;
			updatePos();
			return possibleMoves[i].type;
		}
	}

	return move_type::none;
}

bool Piece::checkLine(int& posx, int& posy, std::vector<Piece*> pieces)
{
	bool addLine = true, addMove = true;
	for (int j = 0; j < pieces.size(); j++) {
		if (pieces[j]->currentPos == Vector2i(posx, posy)) {
			addLine = false;

			if (pieces[j]->color == color) addMove = false;
			else addMove = true;
		}
	}
	if (addMove) {
		move_type addType;
		if (!addLine) addType = move_type::capture;
		else addType = move_type::move;

		possibleMoves.push_back(moveType(Vector2i(posx, posy), addType));
	}

	return !addLine;
}

knight_struct Piece::checkIfNewPosOk(Vector2i pos, std::vector<Piece*>& pieces)
{
	if (pos.x > squareNumber || pos.x < 0 || pos.y > squareNumber || pos.y < 0) return knight_struct(false);

	for (int i = 0; i < pieces.size(); i++) {
		if (pieces[i]->currentPos == pos) {
			if (pieces[i]->color != color) return knight_struct(true, move_type::capture);
			else return knight_struct(false);
		}
	}
	return knight_struct(true, move_type::move);
}

void Piece::updatePos()
{
	sprite.setPosition(currentPos.x * squareLength, currentPos.y * squareLength);
}
