// homework.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
using namespace std;
int getthesize(int size)
{
	cout << "input the size of matrix\n";
	cin >> size;
	return size;
}
void matrixinic(int**& matrix, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			matrix[i][j] = rand() % 100 + 1;
		}
	}
}
void display(int** matrix, int size)
{
	cout << "This is our matrix\n";
	for (int i = 0; i < size; i++)
	{
		cout << "[";
		for (int j = 0; j < size; j++)
		{
			cout << matrix[i][j] << "|";
		}
		cout << "]\n";
	}
}
int main() {
	int size = getthesize(size);
	int **matrix = (int**)malloc(sizeof(int*) * size);
	for (int i = 0; i < size; i++)
	{
		matrix[i] = (int*)malloc(sizeof(int) * size);
	}
	matrixinic(matrix, size);
	display(matrix, size);
	for (int i = 0; i < size; i++)
	{
		free(matrix[i]);
		matrix[i] = nullptr;
	}
	free(matrix);
	matrix = nullptr;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
