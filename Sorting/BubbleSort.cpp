#include <iostream>
using namespace std;

void swap(int arr[],int i, int j);
void bubble_sort(int arr[],int n);

void bubble_sort(int arr[], int n) {
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < n-i-1; j++) {
			if(arr[j] > arr[j+1]) {
				swap(arr,j,j+1);
			}
		}
	}
}

void recursive_bubble_sort(int arr[], int n) {
	for (int i = 0; i < n-1; i++) {
		if (arr[i] > arr[i+1]) {
			swap(arr,i,i+1);
		}
	}
	if (n == 0)
		return;
	recursive_bubble_sort(arr,n-1);
}

void swap(int arr [],int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int main() {
	int arr [] = {5,1,2,7,3};
	recursive_bubble_sort(arr,5);
	cout<<"Sorted Array"<<endl;
	for (int i = 0; i < 5; i ++)
		cout<<arr[i]<<" ";
}
