// Andrew Trang
// Exercise 3
// Completed 1/27/2016

#include <iostream>
#include <cmath>

double sum(double values[], int size);
double mean(double values[], int size);
double stdDev(double values[], int size);

int main(){
	const int size = 10;
	double val[size];

	for (int i = 0; i < size; ++i){
		std::cout << "Enter a number for index " << i << ": ";
		std::cin >> val[i];
	}

	std::cout << "Standard Deviation: " << stdDev(val, size);
	std::cin.get();
	std::cin.get();
	return 0;
}
double sum(double values[], int size){
	double temp = 0;

	for (int i = 0; i < size; i++)
		temp += values[i];
	return temp;
}
double mean(double values[], int size){
	return sum(values, size)/size;
}
double stdDev(double values[], int size){
	double temp = mean(values, size);

	for (int i = 0; i < size; i++)
		values[i] = pow(values[i] - temp, 2);
	
	return sqrt(sum(values,size));
}