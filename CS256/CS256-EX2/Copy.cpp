// Andrew Trang
// Exercise 2
// Completed 1/18/2016

#include <iostream>
#include <string>
#include <fstream>

int main(){
	int count = 0;
	std::string val;
	std::string input;
	std::string output;
	std::cout << "Enter from file: ";
	std::getline(std::cin, input);
	std::ifstream fin(input);

	if (fin){
		std::cout << "Enter to file: ";
		std::getline(std::cin, output);
		std::ofstream fout(output);

		while (fin >> val){
			count += val.length();
			fout << val << std::endl;
		}
		std::cout << "Copied " << count << " characters." << std::endl;
	} else
		std::cout << "File not found.";
	std::cin.get();
}