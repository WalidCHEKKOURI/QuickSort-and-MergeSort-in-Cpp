#include <string>
#include <iostream>

using namespace std;

void swap(int* a, int* b)
{

	int temp = *a;
	*a = *b;
	*b = temp;

}


int partition(int arr[], int l, int h)
{

	int pivot = arr[l];
	int i = l, j =h;

	do {
	
		do { i++; } while (arr[i] <= pivot);
		do { j--; } while (arr[j] > pivot);

		if (i < j)swap(&arr[i], &arr[j]);
	
	} while (i<j);
	swap(&arr[l], &arr[j]);

	return j;

}


void quickSort(int arr[], int l, int h)
{
	
	if (l < h)
	{
		int j = partition(arr, l, h);
		quickSort(arr, l, j);
		quickSort(arr, j+1, h);
	}

}


void display(int arr[], const int N)
{

	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << endl;
	}


}

int main()
{
	
	int arr[] = {90,13,7,12,16,9,24,5,10,1};
	const int N = 10;

	quickSort(arr, 0, N);


	display(arr, N);


	system("pause");
	return 0;
}