#include <iostream>
using namespace std;

int* countingSort(int arr [], int size);

int maxValue(int arr [], int size ){
	int max = arr[0];
	
	for(int i=0; i<size; i++) {
		if(max < arr[i]) max = arr[i];
	}
	
	return max;
}

int* countingSort(int arr [], int size) {
	// Find the maximum value of the array
	int k = maxValue(arr,size);
	
	//Create your helper arrays
	int* C = new int[k+1];
	int* B = new int[size];
	
	//Set all of the values in array C equal to 0
	for(int i=0;i<k+1;i++) C[i] = 0;
	
	//Array C contains how many times a certain number has occured
	for(int i=0;i<size;i++) C[arr[i]] += 1;
	
	//Array C contains all of number of elements that is less than or equal to i
	for(int i=1;i<k+1;i++) C[i] += C[i-1];
	
	//Sort the values
	for(int i=size-1;i>=0;i--){
		int value = arr[i];
		B[C[arr[i]]-1] = value;
		C[arr[i]] -= 1;
	}
	
	delete C;
	
	return B;
}

int main() {
	int array [] = {2,5,3,0,2,3,0,3};
	cout<<"Unsorted Array"<<endl;
	for(int i =0; i<8; i++) cout<< array[i] <<" ";
	cout<<endl;
	int *sortedArray = countingSort(array,8);
	cout<<"Sorted Array"<<endl;
	for(int i =0; i<8; i++) cout<< sortedArray[i] <<" ";
}
