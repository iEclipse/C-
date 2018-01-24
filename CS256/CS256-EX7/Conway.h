// Andrew Trang
// Exercise 7
// Completed 2/24/2016

#ifndef CONWAY_H
#define CONWAY_H
#include <string>

class Conway {
private:
	bool **board;
	int rows;
	int cols;
public:
	Conway();
	~Conway();
	Conway(const std::string fileName);
	Conway(const Conway& other);
	void operator=(const Conway& other);
	bool alive(int row, int col);
	void flip(int row, int col);
	void step();
	void play(int n);
	std::string str() const;
};

#endif