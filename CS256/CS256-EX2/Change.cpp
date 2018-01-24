// Andrew Trang
// Exercise 2
// Completed 1/18/2016

#include <iostream>

int main(){
	int val;
	std::cout << "Enter a number in the range [0, 99] : ";
	std::cin >> val;
	if (val < 0 || val > 99)
		std::cout << "ERROR: The argument is invalid.";
	else{
		if (val == 0)
			std::cout << "There is no change." << std::endl;
		else
			std::cout << "The proper change is:" << std::endl;
		if (val >= 25){
			std::cout << (val/25);
			if (val/25 > 1)
				std::cout << " quarters." << std::endl;
			else
				std::cout << " quarter." << std::endl;
			val %= 25;
		}
		if (val >= 10){
			std::cout << (val/10);
			if (val/10 > 1)
				std::cout << " dimes." << std::endl;
			else
				std::cout << " dime." << std::endl;
			val %= 10;
		}
		if (val >= 5){
			std::cout << (val/5);
			if (val/5 > 1)
				std::cout << " nickels." << std::endl;
			else
				std::cout << " nickel." << std::endl;			val %= 5;
		}
		if (val >= 1){
			std::cout << (val);
			if (val > 1)
				std::cout << " pennies." << std::endl;
			else
				std::cout << " penny." << std::endl;
		}
		std::cin.get();
		std::cin.get();
		return 0;
	}
}