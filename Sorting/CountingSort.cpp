#include <iostream>
#include <bits/stdc++.h> 
# define my_sizeof(type) ((char *)(&type+1)-(char*)(&type)) 
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

int max_value(int arr [], int n) {
	int value = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > value)
			value = arr[i];
	return value;
}

void counting_sort(int arr[],int size) {
	int max = max_value(arr,size);
	int *B = new int[max+1];
	
	for (int i = 0; i < max; i++) 
		B[i] = 0;
	
	for (int i = 0; i < size; i++)
		B[arr[i]] += 1;
	
	int j = 0;
	for (int i = 0; i < max+1; i++) {
		int occurences = B[i];
		if (occurences > 0) {
			for (int k = 0; k < occurences; k++)
				arr[j++] = i;
		}
	}
}

int main() {
	int array [] = {2,5,3,0,2,3,0,3};
	cout<<"Unsorted Array"<<endl;
	for(int i =0; i<8; i++) cout<< array[i] <<" ";
	cout<<endl;
	counting_sort(array,8);
	//int *sortedArray = countingSort(array,8);
	cout<<"Sorted Array"<<endl;
	for(int i =0; i<8; i++) cout<< array[i] <<" ";
}
