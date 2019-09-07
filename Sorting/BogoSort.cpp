#include <iostream>
#include <stdlib.h> 
#include<time.h> 
using namespace std;

void bogo_sort(int arr [], int n);
void swap(int val1, int val2);
bool is_sorted(int arr [], int n);

void swap(int arr [],int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}
bool is_sorted(int arr [], int n) {
	for (int i = 0; i < n - 1 ; i++) {
		if (!(arr[i] < arr[i+1]))
			return false;
	}
	
	return true;
}

void bogo_sort(int arr [], int n) {
	srand(time(0));
	while(!is_sorted(arr,n)) {
		for (int i = 0; i < n; i++) {
			swap(arr,i,rand()%n);
		}
	}
}

int main() {
	int arr [] = {4,2,1,3};
	bogo_sort(arr,4);
	cout<<"Sorted Array"<<endl;
	for (int i = 0; i < 4; i ++)
		cout<<arr[i]<<" ";
}
