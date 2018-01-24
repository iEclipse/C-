// Andrew Trang
// Exercise 4
// Completed 1/30/2016

#include <iostream>

using namespace std;

int*** alloc3D(int x, int y, int z);
void dealloc3D(int*** array, int x, int y);

int main()
{
	while (true)
	{
		int*** a = alloc3D(100, 100, 100);
		dealloc3D(a, 100, 100);
	}
	return 0;
}

int*** alloc3D(int x, int y, int z){
	int*** result = new int**[x];
	for (int i = 0; i < x; ++i){
		result[i] = new int*[y];
		for (int j = 0; j < y; ++j)
			result[i][j] = new int[z];
	}
	return result;
}

void dealloc3D(int*** array, int x, int y){
	for (int i = 0; i < x; ++i){
		for (int j = 0; j < y; ++j){
			delete [] array[i][j];
			array[i][j] = nullptr;
		}
		delete [] array[i];
		array[i] = nullptr;
	}
	delete [] array;
	array = nullptr;
}
