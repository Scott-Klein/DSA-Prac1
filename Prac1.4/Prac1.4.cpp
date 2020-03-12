
#include <iostream>
#include <time.h>
#include <vector>
using namespace std;

#define nine 9
void Setup();
void GenerateRandomPositions(vector<int>& randomPositions);
int GetNewRandom();
void WriteToArray(vector<int>& arr, vector<int>& randomPositions);
void PrintArray(vector<vector<int>> results);
void PrintVector(vector<int> result);

static int randomCalls;
static vector<int> candidatePositions;
vector<int> arr;
vector<int> randomPositions;

int main()
{
	srand(time(NULL));
	vector<vector<int>> allResults;
	for (int i = 0; i < 10; i++)
	{
		Setup();
		GenerateRandomPositions(randomPositions);
		WriteToArray(arr, randomPositions);
		arr[9] = randomCalls;
		allResults.push_back(arr);
	}

	PrintArray(allResults);
}

void GenerateRandomPositions(vector<int>& positions)
{
	for (int i = 0; i < 6; i++)
	{
		positions[i] = GetNewRandom();
	}
}

int GetNewRandom()
{
	int randomNum;

	randomNum = rand() % candidatePositions.size();

	int result = candidatePositions[randomNum];
	candidatePositions.erase(candidatePositions.begin() + randomNum);

	randomCalls++;

	return result;
}


void WriteToArray(vector<int>& arr, vector<int>& randomPositions)
{
	for (int i = 0; i < 6; i++)
	{
		arr[randomPositions[i]] = i + 1;
	}
}

void PrintArray(vector<vector<int>> results)
{
	for (int i = 0; i < results.size(); i++)
	{
		PrintVector(results[i]);
		cout << "Random calls: " << results[i][9] << endl;
	}

}

void PrintVector(vector<int> result)
{
	for (int i = 0; i < result.size() - 1; i++)
	{
		cout << result[i] << " ";
	}
}



void Setup()
{

	arr = { 0,0,0,0,0,0,0,0,0,0 };
	randomPositions = { 0,0,0,0,0,0 };
	candidatePositions = { 0,1,2,3,4,5,6,7,8 };
	randomCalls = 0;
}
