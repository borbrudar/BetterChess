#pragma once

const int SCR_WIDTH = 600, SCR_HEIGHT = SCR_WIDTH;
const int squareNumber = 8;
const int squareLength = SCR_WIDTH / squareNumber;
const int realSquareSize = 213;

enum class piece {
	rook,
	knight,
	bishop,
	king,
	queen,
	pawn,
	empty
};

enum class color_type {
	white,
	black,
	none
};
