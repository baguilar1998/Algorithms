#include <iostream>
using namespace std;

void swap(int arr[],int i, int j);
void cocktail_sort(int arr[],int n);

void cocktail_sort(int arr[], int n) {
	bool swapped = true;
	int start = 0;
	int end = n-1;
	while(swapped) {
		swapped = false;
		for(int i = start; i < end; i++) {
			if(arr[i] > arr[i+1]) {
				swapped = true;
				swap(arr,i,i+1);
			}
		}
		if(!swapped)
			break;
		end = end -1;
		for(int i = end-1; i >= start; i--) {
			if(arr[i]>arr[i+1]) {
				swapped = true;
				swap(arr,i,i+1);
			}
		}
		start = start+1;
	}
}
void swap(int arr [],int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int main() {
	int arr [] = {790,99,898,88,606,351,736,928,553,576};
	cocktail_sort(arr,10);
	cout<<"Sorted Array"<<endl;
	for (int i = 0; i < 10; i ++)
		cout<<arr[i]<<" ";
}
