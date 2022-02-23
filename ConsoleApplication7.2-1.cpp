﻿#include <iostream>
#include <iomanip>
#include <time.h>


using namespace std;
void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** a, const int rowCount, const int colCount);
int MaxMinOdd(int** a, const int rowCount, const int colCount);

int main()
{
	srand((unsigned)time(NULL));

	int Low = 4; 
	int High = 45; 
	int rowCount; 
	int colCount; 
	cout << "k = "; cin >> rowCount;
	cout << "n = "; cin >> colCount;


	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];
	Create(a, rowCount, colCount, Low, High);
	Print(a, rowCount, colCount);
	int minMax = MaxMinOdd(a, rowCount, colCount);
	cout << minMax << endl;
	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low,
	const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}

int MaxMinOdd(int** a, const int rowCount, const int colCount)
{
	int min, max;
	for (int i = 0; i < rowCount; i++)
	{
		if (i % 2 == 0) 
		{
			min = a[i][0];
			for (int j = 1; j < colCount; j++)
			{
				if (a[i][j] < min)
				{
					min = a[i][j];
				}
			}
			max = a[i][0];
			for (int j = 1; j < colCount; j++)
			{
				if (a[i][j] < max)
				{
					max = a[i][j];
				}
			}
			if (i == 1) 
			{
				max = min;
			}
			if (min > max)
			{
				max = min;
			}
		}
	}
	return max;
}
