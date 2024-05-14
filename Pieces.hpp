#include <iostream>
#include <vector>

using namespace std;

class Pieces{
	private:
		vector<vector<vector<bool>>> pieces;
	public:
		Pieces();
		vector<vector<bool>> Tetriminous(int ind);
		void RotatePiece(int ind);
		void DerotatePiece(int ind);
};
