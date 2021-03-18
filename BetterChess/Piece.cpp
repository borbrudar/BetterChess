#include "Piece.h"

Texture Piece::texture;

void Piece::loadTexture(const char* path)
{
	if (!texture.loadFromFile(path))
		std::cout << "Couldnt load texture" << std::endl;
}

void Piece::init(color_type pieceColor)
{
	int x = choosePieceTexture(), y;
	if (pieceColor == color_type::white) y = 0;
	else y = realSquareSize;

	IntRect temp = IntRect(x,y, realSquareSize, realSquareSize);

	sprite.setTexture(&texture);
	sprite.setTextureRect(temp);
	sprite.setSize(Vector2f(SCR_WIDTH / squareNumber, SCR_HEIGHT / squareNumber));

	color = pieceColor;
}

void Piece::draw(RenderWindow& window)
{
	sprite.setPosition(currentPos.x * squareLength, currentPos.y * squareLength);
	window.draw(sprite);
}

move_type Piece::checkNewPos(Vector2i newPos)
{
	for (int i = 0; i < possibleMoves.size(); i++) {
		if (possibleMoves[i].move == newPos) {
			currentPos = newPos;
			hasMoved = true;
			return possibleMoves[i].type;
		}
	}

	return move_type::none;
}

bool Piece::checkLine(int& posx, int& posy, std::vector<std::unique_ptr<Piece>>& pieces)
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

check_struct Piece::checkIfNewPosOk(Vector2i pos, std::vector<std::unique_ptr<Piece>>& pieces)
{
	if (pos.x > squareNumber || pos.x < 0 || pos.y > squareNumber || pos.y < 0) return check_struct(false);

	for (int i = 0; i < pieces.size(); i++) {
		if (pieces[i]->currentPos == pos) {
			if (pieces[i]->color != color) return check_struct(true, move_type::capture);
			else return check_struct(false);
		}
	}
	return check_struct(true, move_type::move);
}

int Piece::choosePieceTexture()
{
	switch (pieceType) {
	case piece::king:
		return 0; break;
	case piece::queen:
		return realSquareSize;	break;
	case piece::bishop:
		return 2 * realSquareSize;	break;
	case piece::knight:
		return 3 * realSquareSize;	break;
	case piece::rook:
		return 4 * realSquareSize;	break;
	case piece::pawn:
		return 5 * realSquareSize;	break;
	}
}

void Piece::resetPassant()
{
	enPassant = false;
}

bool Piece::isPromoted()
{
	return false;
}
