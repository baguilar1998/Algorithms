#include <iostream>
using namespace std;

void heap_sort(int arr[], int n);
void heapify(int arr[], int n , int i);
void swap(int arr [],int i, int j);

void swap(int arr [],int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void heap_sort(int arr[], int n) {
	for (int i = n/2-1; i >= 0; i--) 
		heapify(arr,n,i);
	for (int i = n-1; i >= 0; i--) {
		swap(arr[0], arr[i]);
		heapify(arr,i,0);
	}
}

void heapify(int arr[], int n, int i) {
	int largest = i;
	int left = (2*i)+1;
	int right = (2*i)+2;
	
	if(left < n && arr[left] > arr[largest])
		largest = i;
	
	if (right < n && arr[right] > arr[largest])
		largest = i;
	
	if (i != largest) {
		swap(arr[largest], arr[i]);
		heapify(arr,n,largest);
	}
}

int main() {
	int arr [] = {7,2567,1,367,12,8,3,69087,235,82,6765};
	int n = sizeof(arr)/sizeof(arr[0]);
	heap_sort(arr,n);
	cout<<"Sorted Array"<<endl;
	for (int i = 0; i < n; i++)
		cout<<arr[i]<<" ";
}
