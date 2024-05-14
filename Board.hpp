#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstring>
#include <time.h>
#include "Pieces.hpp"

#define row 20
#define col 10

using namespace sf;
using namespace std;

class Board : public Drawable {
private:
	Pieces pieces;
	int indNewTetriminous = 0, indTetriminousColor = 0;
	Color tetriminousColor;

	int indX = 0, indY = 0;
	
	int timer = 0;
	int limitTimer = 30;

	const int boardRow = row, boardCol = col;
	const int cellWidth = 30, cellHeight = 30;

	int board[row][col];
	RectangleShape boardShapes[row][col];

	const int screenWidth = boardCol * cellWidth * 2;
	const int screenHeight = boardRow * cellHeight;
public:
	Board();
	int getScreenWidth() const;
	int getScreenHeight() const;
	bool createNewTetriminous();
	bool UpdateBoard();
	void UpdateBoardColors();
	void UpdateLimitTimer(int l);
	void Right();
	void Left();
	void RotatePiece();
	int CheckLine();
	void ClearBoard();
	virtual void draw(RenderTarget&, RenderStates) const;
};