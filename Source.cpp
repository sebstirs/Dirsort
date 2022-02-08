#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
//comparator for sort algorithm
bool comparator(string a, string b)
{
	return a < b;
}
//swap two integers
void swap(int* x, int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}
//swap two strings
void swap(string *x, string *y) {
	string temp = *x;
	*x = *y;
	*y = temp;
}
//sort function
string dirSort(string arr[], int size) {
	int count = 0;
	int slashCount[11];
	int i = 0;
	int n = sizeof(arr) / sizeof(arr[0]);
	//sort alphabetically
	sort(arr, arr + size, less<string>());
	//count number of slashes in dir
	while (i < size) {
		string currentString = arr[i];
		int count = 0;
		for (int i = 0; i < currentString.size(); i++) {
			char currentChar = currentString[i];
			if (currentChar == '/') {
				count++;
			}
		}
		slashCount[i] += count;
		i++;
	}
	//bubble sort by number of slashes
	for (int i = 0; i < size; i++) {
		int x = 0;
		while (x + 1 < size) {
			if (slashCount[x] > slashCount[x+1]) {
				swap(&slashCount[x], &slashCount[x+1]);
				swap(&arr[x], &arr[x + 1]);
			}
			x++;
		}
	}
	//print out array
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << endl;
	}

	return "success";
};

int main() {

	string dirSort(string arr[], int size);

	string exampleA[8] = {"/", "/usr/", "/usr/local/", "/usr/local/bin/", "/games/", "/games/snake/", "/homework/", "/temp/downloads/"};
	string exampleB[7] = {"/usr/", "/usr/local/", "/bin/", "/usr/local/bin/", "/usr/bin/", "/bin/local/", "/bin/local/"};
	string exampleC[8] = {"/", "/a/", "/b/", "/c/", "/d/", "/e/", "/f/", "/g/" };
	string exampleD[11] = {"/", "/a/", "/b/", "/c/", "/d/", "/e/", "/f/", "/g/", "/a/a/", "/b/g/c/", "/g/f/"};
	string exampleE[7] = {"/a/b/c/d/e/f/g/h/i/j/k/l/m/n/", "/o/p/q/r/s/t/u/v/w/x/y/z/"};

	cout << "Example A" << endl;
	string exA = dirSort(exampleA, 8);
	cout << endl << "Example B" << endl;
	string exB = dirSort(exampleB, 7);
	cout << endl << "Example C" << endl;
	string exC = dirSort(exampleC, 8);
	cout << endl << "Example D" << endl;
	string exD = dirSort(exampleD, 11);
	cout << endl << "Example E";
	string exE = dirSort(exampleE, 7);

	return 0;
}