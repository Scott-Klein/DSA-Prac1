#include <iostream>
#include <string>
using namespace std;

template <class Type>
void funcExp(Type list[], int size);

int list[10] = { 5,3,2,10,4,19,45,13,61,11 }; 
string strList[] = { "One", "Hello", "Four", "Three", "How", "Six" };


int main()
{
	cout << "A:\n";
	funcExp(list, 10);

	cout << "B:\n";
	funcExp(strList, 6);

}



//For numbers prints the largest number, then smallest
// For strings prints the latest word in dictionary order, then the earliest.
template <class Type>
void funcExp(Type list[], int size) 
{ 
	Type x = list[0]; 

	Type y = list[size - 1]; 
	for (int j = 1; j < size; j++) 
	{ 
		//Finds the largest number starting from the front of the list.
		if (x < list[j])
			x = list[j];

		//Finds the smallest number starting from the back of the list.
		if (y > list[size - 1 - j])
			y = list[size - 1 - j];
	}
	cout << x << endl; 
	cout << y << endl; 
}