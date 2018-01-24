// Andrew Trang
// Homework 2
// Completed 1/22/2016

#include <iostream>

int main(){
	int val;
	int space = 0;
	bool toggle = false; 
	std::cout << "Enter a positive integer: ";
	std::cin >> val;
	if (val > 0){
		for (int i = 0; i < val; ++i){ 
			for (int j = 0; j <= space; j++)
				std::cout << " "; 
			std::cout << "XXXXXXXXXXXXXXXXXXX" << std::endl;
			if (!toggle && space < 50)
				++space;
			else if (toggle && space > 0) 
				--space;
			else if (!toggle && space == 50){
				--space; 
				toggle = !toggle; 
			}
			else{ //Otherwise
				++space;
				toggle = !toggle;
			}
		}
	}
	else
		std::cout << "ERROR: Invalid number specified." << std::endl;
	std::cin.get(); 
	std::cin.get(); 
	return 0; 
}