// Andrew Trang
// Exercise 7
// Completed 2/24/2016

#include "Conway.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

Conway::Conway() {}

Conway::Conway(const std::string fileName) {
	ifstream fin(fileName);
	fin >> rows;
	fin >> cols;
	board = new bool*[rows];
	for (int i = 0; i < rows; ++i)
		board[i] = new bool[cols];
	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < cols; ++j)
			fin >> board[i][j];
}

Conway::Conway(const Conway& other) {
	rows = other.rows;
	cols = other.cols;
	board = new bool*[other.rows];
	for (int i = 0; i < other.rows; ++i)
		board[i] = new bool[other.cols];
	for (int i = 0; i < other.rows; ++i)
		for (int j = 0; j < other.cols; ++j)
			board[i][j] = other.board[i][j];
}

Conway::~Conway() {
	for (int i = 0; i < rows; ++i)
		delete[] board[i];
	delete[] board;
}
void Conway::operator=(const Conway& other) {
	for (int i = 0; i < rows; ++i)
		delete[] board[i];
	delete[] board;
	rows = other.rows;
	cols = other.cols;
	board = new bool*[other.rows];
	for (int i = 0; i < other.rows; ++i)
		board[i] = new bool[other.cols];
	for (int i = 0; i < other.rows; ++i)
		for (int j = 0; j < other.cols; ++j)
			board[i][j] = other.board[i][j];
}

bool Conway::alive(int row, int col) {
	return board[row][col];
}

void Conway::flip(int row, int col) {
	board[row][col] = board[!board[row]][!board[row][col]];
}

void Conway::step() {
	Conway temp = Conway(*this);
	for (int i = 0; i < rows; ++i) {
		for (int j = 0, k = 0; j < cols; ++j, k = 0) {
			if (i < (rows-1) && j < (cols-1) && board[i + 1][j + 1])
				++k;
			if (i > 0 && j < (cols-1) && board[i - 1][j + 1])
				++k;
			if (i < (rows-1) && j > 0 && board[i + 1][j - 1])
				++k;
			if (i > 0 && j > 0 && board[i-1][j-1])
				++k;
			if (i > 0 && board[i - 1][j])
				++k;
			if (j > 0 && board[i][j - 1])
				++k;
			if (j < (cols-1) && board[i][j + 1])
				++k;
			if (i < (rows-1) && board[i + 1][j])
				++k;
			if (k < 2 || k > 3)
				temp.board[i][j] = 0;
			else if (k == 3)
				temp.board[i][j] = 1;
		}
	}
	*this = temp;
}

void Conway::play(int n) {
	for (int i = 0; i < n; ++i)
		step();
}
int main(int argc, char *argv[]) {
	if (argc > 2) {
		Conway c(argv[1]);
		c.play(atoi(argv[2]));
		c.str();
	} return 0;
}

std::string Conway::str() const {
	stringstream sout;	
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j)
			sout << board[i][j] << " ";
		sout << "\n";
	} for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (board[i][j] == true) cout << 'X'<< " ";
			else cout << '.'<<" ";
		} cout << endl;
	} return sout.str();
}