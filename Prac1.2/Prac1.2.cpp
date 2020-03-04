// Prac1.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>

using namespace std;

#define nine 9
void Setup();
void GenerateRandomPositions(int randomPositions[]);
int GetNewRandom();
void WriteToArray(int arr[], int randomPositions[]);
void PrintArray(int arr[]);
int OccurancesOf(int numChecked, int arr[]);

static int randomCalls = 0;
static int occuredNumbers[6] = { 0,0,0,0,0,0 };
static int occuredNumberIndex = 0;

int main()
{
	int arr[9] = { 0,0,0,0,0,0,0,0,0 };
	int randomPositions[6] = { 0,0,0,0,0,0 };
	GenerateRandomPositions(randomPositions);
	WriteToArray(arr, randomPositions);

	PrintArray(arr);
	
}

void GenerateRandomPositions(int positions[])
{
	Setup();

	for (int i = 0; i < 6; i++)
	{
		positions[i] = GetNewRandom();
		
	}
}

int GetNewRandom()
{
	int randomNum;
	do
	{
		randomNum = rand() % 9 + 1;
		randomCalls++;
	} while (OccurancesOf(randomNum, occuredNumbers) > 0);

	occuredNumbers[occuredNumberIndex++] = randomNum;

	return randomNum;
}


void WriteToArray(int arr[], int randomPositions[])
{
	for (int i = 0; i < 6; i++)
	{
		arr[randomPositions[i]] = i + 1;
	}
}

void PrintArray(int arr[])
{
	for (int i = 0; i < nine; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "Random calls: " << randomCalls << endl;
}

int OccurancesOf(int numChecked, int arr[])
{
	int occurances = 0;
	for (int i = 0; i < 6; i++)
	{
		if (numChecked == arr[i])
		{
			occurances++;
		}
	}
	return occurances;
}

void Setup()
{
	srand(time(NULL));
}
