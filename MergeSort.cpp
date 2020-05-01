#include <string>
#include <iostream>

using namespace std;


void merge(int arr[], int l, int mid, int h)
{

	int i=l, j=mid+1, k=l;
	int arr2[100];

	while (i <= mid && j <= h)
	{
		if (arr[i] < arr[j])
			arr2[k++] = arr[i++];
		else
			arr2[k++] = arr[j++];
	}

	for (; i <= mid; i++)
		arr2[k++] = arr[i];

	for (; j <= h; j++)
		arr2[k++] = arr[j];

	for (int i = l; i <= h; i++)
		arr[i] = arr2[i];
}

void mergeSort(int arr[], int l, int r)
{
	if (l < r)
	{
		// Same as (l+r)/2, but avoids overflow for 
		// large l and h 
		//int m = l + (r - l) / 2;
		int m =( l + r ) / 2;

		// Sort first and second halves 
		
		mergeSort(arr, l, m);

		
		mergeSort(arr, m + 1, r);

		
		merge(arr, l, m, r);

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
	
	int arr[] = {10,9,8,7,6,5,4,3,2,1};
	const int N = 10;


	mergeSort(arr, 0, N-1);

	display(arr, N);


	system("pause");
	return 0;
}