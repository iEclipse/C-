// Andrew Trang
// Homework 1
// Completed 1/14/2016

#include <iostream>
#include <cmath>

int main()
{
	int age, ageSquared, ageHalved;
	std::cout << "Enter your age: ";
	std::cin >> age;
	ageSquared = pow(age,2);
	ageHalved = age / 2;
	std::cout << "\n[age, ageSquared, ageHalved]: " << age << ", " << ageSquared << ", " << ageHalved << std::endl;
	std::cout << "[age * ageHalved]: " << (age * ageHalved) << std::endl;
	std::cout << "[ageSquared / ageHalved]: " << (ageSquared / ageHalved) << std::endl;
	std::cout << "[ageSquared % ageHalved]: " << (ageSquared % ageHalved) << std::endl;
	std::cout << "[age - ageHalved]: " << (age - ageHalved) << std::endl;
	std::cout << "[age / ageSquared]: " << (age / ageSquared) << std::endl;
	std::cout << "[age + ageSquared]: " << (age + ageSquared) << std::endl;
	std::cout << "[(age + ageSquared + ageHalved) / 3]: " << ((double)(age + ageSquared + ageHalved) / 3) << std::endl;
	std::cout << "\nPress 'enter' to exit..";
	std::cin.get();
	std::cin.get();
	return 0;
}