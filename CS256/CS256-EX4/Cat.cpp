// Andrew Trang
// Exercise 4
// Completed 1/30/2016

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void print(string file){
	string text = "";
	ifstream fin(file);

	if (fin.fail())
		cout << "Error: Invalid file specified." << endl;
	
	while (fin >> text)
		cout << text << endl;
}

int main(int argc, char* argv[]){
	if (argc == 1)
		cout << "Error: You did not provide any arguments." << endl;
	else
		for (int i = 0; i<argc; ++i)
			print(argv[i]);
	cout << "Press 'enter' to continue..";
	cin.get();
	return 0;
}