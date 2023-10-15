// C++ implementation of QuickSort by taking first element as pivot 
#include <bits/stdc++.h>
using namespace std;

/* Time Complexity:
Average Case: O(N * logN), where N is the length of the array.
Best Case: O(N * logN)
Worst Case: O(N2)
Auxiliary Space: O(1)*/
int partition(int arr[], int low, int high)
{

	int pivot = arr[low];
	int st = low; // st points to the starting of array
	int end = high; // end points to the ending of the array
	int k = high;
	for (int i = high; i > low; i--) {
		if (arr[i] > pivot)
			swap(arr[i], arr[k--]);
	}
	swap(arr[low], arr[k]);
	return k;
}

void quickSort(int arr[], int low, int high)
{

	if (low < high) {
		int idx = partition(arr, low, high);
		quickSort(arr, low, idx - 1);
		quickSort(arr, idx + 1, high);
	}
}

void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	int arr[] = { 7, 6, 10, 5, 9, 2, 1, 15, 7 };
	int n = sizeof(arr) / sizeof(arr[0]);
	quickSort(arr, 0, n - 1);
	cout << "Sorted array: \n";
	printArray(arr, n);
	return 0;
}


