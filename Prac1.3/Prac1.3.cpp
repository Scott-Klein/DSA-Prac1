
#include <iostream>
#include <time.h>
#include <vector>
using namespace std;

#define nine 9
void Setup();
void GenerateRandomPositions(int randomPositions[]);
int GetNewRandom();
void WriteToArray(int arr[], int randomPositions[]);
void PrintArray(vector<int[10]> results);
int OccurancesOf(int numChecked, int arr[]);

static int randomCalls;
static int occuredNumbers[6] = { 0,0,0,0,0,0 };
static int occuredNumberIndex = 0;

int main()
{
	vector<int[10]> allResults;

	randomCalls = 0;
	int arr[10] = { 0,0,0,0,0,0,0,0,0,0 };
	int randomPositions[6] = { 0,0,0,0,0,0 };
	GenerateRandomPositions(randomPositions);
	WriteToArray(arr, randomPositions);
	arr[9] = randomCalls;
	allResults.push_back(arr);

	PrintArray(allResults);
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

void PrintArray(vector<int[10]> results)
{
	for (int i = 0; i < results.size(); i++)
	{
		int* arr = results[i];

		for (int j = 0; j < 9; j++)
		{
			cout << arr[i] << " ";
		}
		cout << "Random calls: " << arr[9] << endl;
	}
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
