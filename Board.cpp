#include "Board.hpp"

Board::Board(){
	memset(board, 0, sizeof(board));
	for(int i = 0; i < boardRow; i++) {
		for(int j = 0; j < boardCol; j++) {
			boardShapes[i][j] = RectangleShape(Vector2f(cellWidth, cellHeight));
			boardShapes[i][j].setPosition(j*cellWidth, i*cellHeight);
			boardShapes[i][j].setFillColor(Color(50, 50, 50));
			boardShapes[i][j].setOutlineThickness(2);
			boardShapes[i][j].setOutlineColor(Color(0, 0, 0));
		}
	}
}

int Board::getScreenWidth() const {
	return screenWidth;
}

int Board::getScreenHeight() const {
	return screenHeight;
}

bool Board::createNewTetriminous() {
	srand((int)time(NULL));
	indNewTetriminous = rand() % 7;
	
	vector<vector<bool>> selectedPiece = pieces.Tetriminous(indNewTetriminous);
	
	int sz = (int)selectedPiece.size();
	indX = (boardCol / 2) - (sz / 2);
	indY = 0;
	
	for(int i = 0; i < sz; i++) {
		for(int j = 0; j < sz; j++) {
			if(selectedPiece[i][j]) {
				if(board[i][j + indX] > 0) return false;
				board[i][j + indX] = -1;
			}
		}
	}
	
	int color = 1 + rand() % 7;
	indTetriminousColor = color;
	
	switch(color){
		case 1: tetriminousColor = Color(255, 166, 0); break;
		case 2: tetriminousColor = Color(245, 152, 245); break;
		case 3: tetriminousColor = Color(51, 204, 153); break;
		case 4: tetriminousColor = Color(255, 110, 110); break;
		case 5: tetriminousColor = Color(255, 204, 77); break;
		case 6: tetriminousColor = Color(166, 166, 255); break;
		case 7: tetriminousColor = Color(138, 194, 247); break;
	}
	return true;
}

bool Board::UpdateBoard() {
	bool limit = 0;
	int aux;

	if (timer >= limitTimer) {
		aux = 0;
		for (int i = boardRow-2; i >= 0; i--) {
			for (int j = 0; j < boardCol; j++) {
				if (board[i][j] == -1) {
					if (board[i + 1][j] <= 0) aux++;
				}
			}
		}

		if (aux == 4) {
			indY++;
			for (int i = boardRow-2; i >= 0; i--) {
				for (int j = 0; j < boardCol; j++) {
					if (board[i][j] == -1) {
						board[i][j] = 0;
						board[i + 1][j] = -1;
					}
				}
			}
		}
		else {
			for (int i = boardRow-1; i >= 0; i--) {
				for (int j = 0; j < boardCol; j++) {
					if (board[i][j] == -1) board[i][j] = indTetriminousColor;
				}
			}
			limit = 1;
		}

		timer = 0;
	}

	timer++;
	return limit;
}

void Board::UpdateBoardColors() {
	for(int i = 0; i < boardRow; i++) {
		for(int j = 0; j < boardCol; j++) {
			switch(board[i][j]) {
				case 0: boardShapes[i][j].setFillColor(Color(50, 50, 50)); break;
				case 1: boardShapes[i][j].setFillColor(Color(255, 166, 0)); break;
				case 2: boardShapes[i][j].setFillColor(Color(245, 152, 245)); break;
				case 3: boardShapes[i][j].setFillColor(Color(51, 204, 153)); break;
				case 4: boardShapes[i][j].setFillColor(Color(255, 110, 110)); break;
				case 5: boardShapes[i][j].setFillColor(Color(255, 204, 77)); break;
				case 6: boardShapes[i][j].setFillColor(Color(166, 166, 255)); break;
				case 7: boardShapes[i][j].setFillColor(Color(138, 194, 247)); break;
				default:
					boardShapes[i][j].setFillColor(tetriminousColor);
				break;
			}
		}
	}
}

void Board::UpdateLimitTimer(int l) {
	limitTimer = l;
}

void Board::Right() {
	int aux = 0;
	for (int i = 0; i < boardRow; i++) {
		for (int j = 0; j < boardCol-1; j++) {
			if (board[i][j] == -1) {
				if (board[i][j + 1] <= 0) {
					aux++;
				}
			}
		}
	}

	if (aux == 4) {
		indX++;
		for (int i = 0; i < boardRow; i++) {
			for (int j = boardCol-1; j >= 0; j--) {
				if (board[i][j] == -1) board[i][j] = 0, board[i][j + 1] = -1;
			}
		}
	}
}

void Board::Left() {
	int aux = 0;
	for (int i = 0; i < boardRow; i++) {
		for (int j = 1; j < boardCol; j++) {
			if (board[i][j] == -1) {
				if (board[i][j - 1] <= 0) {
					aux++;
				}
			}
		}
	}

	if (aux == 4) {
		indX--;
		for (int i = 0; i < boardRow; i++) {
			for (int j = 0; j < boardCol; j++) {
				if (board[i][j] == -1) board[i][j] = 0, board[i][j - 1] = -1;
			}
		}
	}
}

void Board::RotatePiece() {
	pieces.RotatePiece(indNewTetriminous);
	vector<vector<bool>> part = pieces.Tetriminous(indNewTetriminous);

	int sz = (int)part.size();

	for (int i = 0; i < sz; i++) {
		for (int j = 0; j < sz; j++) {
			if (part[i][j]) {
				if (indY + i < 0 || indY + i >= boardRow || indX + j < 0 || indX + j >= boardCol || board[indY + i][indX + j] > 0) {
					pieces.DerotatePiece(indNewTetriminous);
					return;
				}
			}
		}
	}

	for (int i = 0; i < boardRow; i++) {
		for (int j = 0; j < boardCol; j++) {
			if (board[i][j] == -1) board[i][j] = 0;
		}
	}

	for (int i = 0; i < sz; i++) {
		for (int j = 0; j < sz; j++) {
			if (part[i][j]) {
				board[i + indY][j + indX] = -1;
			}
		}
	}
}

int Board::CheckLine() {
	int aux, lines = 0;

	for (int i = boardRow-1; i >= 0; i--) {
		aux = 0;
		for (int j = 0; j < boardCol; j++) {
			if (board[i][j] > 0) aux++;
			if (lines > 0) board[i + lines][j] = board[i][j], board[i][j] = 0;
		}
		if (aux == boardCol) {
			for (int j = 0; j < boardCol; j++) board[i][j] = 0;
			lines++;
		}
	}

	return lines;
}

void Board::ClearBoard() {
	memset(board, 0, sizeof(board));
}

void Board::draw(RenderTarget& rt, RenderStates rs) const {
	for (int i = 0; i < boardRow; i++) {
		for (int j = 0; j < boardCol; j++) {
			rt.draw(boardShapes[i][j], rs);
		}
	}
}