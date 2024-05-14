#include "Pieces.hpp"

Pieces::Pieces(){
	pieces= {{{1,1},
			 {1,1}},
			 
			{{0,0,0,0,0},
			 {0,0,1,0,0},
			 {0,0,1,1,0},
			 {0,0,0,1,0},
			 {0,0,0,0,0}},
			 
			{{0,0,0,0,0},
			 {0,0,0,1,0},
			 {0,0,1,1,0},
			 {0,0,1,0,0},
			 {0,0,0,0,0}},
			 
			{{0,0,0,0,0},
			 {0,0,1,1,0},
			 {0,0,1,0,0},
			 {0,0,1,0,0},
			 {0,0,0,0,0}},
			 
			{{0,0,0,0,0},
			 {0,1,1,0,0},
			 {0,0,1,0,0},
			 {0,0,1,0,0},
			 {0,0,0,0,0}},
			 
		    {{0,0,0,0,0},
			 {0,0,1,0,0},
			 {0,0,1,1,0},
			 {0,0,1,0,0},
			 {0,0,0,0,0}},
			 
			{{0,0,1,0},
			 {0,0,1,0},
			 {0,0,1,0},
			 {0,0,1,0}}};
}


vector<vector<bool>> Pieces::Tetriminous(int ind){
	return pieces[ind];
}


void Pieces::RotatePiece(int ind) {
	vector<vector<bool>> temp = pieces[ind];
	int indI = 0,indJ = 0;
	int sz = (int)pieces[ind].size();
	for(int i = 0; i < sz; i++){
		for(int j = sz-1; j >= 0; j--) {
			pieces[ind][indI][indJ] = temp[j][i];
			indJ++;
		}
		indI++;
		indJ = 0;
	}
}

void Pieces::DerotatePiece(int ind) {
	vector<vector<bool>> temp = pieces[ind];
	int indI = 0,indJ = 0;
	int sz = (int)pieces[ind].size();
	for(int i = sz-1; i >= 0; i--) {
		for(int j = 0; j < sz; j++) {
			pieces[ind][indI][indJ] = temp[j][i];
			indJ++;
		}
		indI++;
		indJ = 0;
	}
}

