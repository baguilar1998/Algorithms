#include <iostream>
using namespace std;

int* countingSort(int arr [], int size, int mod, int div);
int* radixSort(int arr[], int size, int digit);
int maxValue(int arr[], int size, int mod, int div);

/*
 * Sorts an integer array based off digits
 * @param arr input array
 * @param size of the input array
 * @param mod the targeted place for the digit
 * @param div helper value to get the digit by itself
*/
int* radixSort(int arr[],int size, int digit) {
	// Make a copy of the original array
	int *temp = arr;
	
	for(int i=0;i<digit;i++) {
		int mod = 10;
		int div=1;
		
		// Get the values needed to get the digit by
		// itself for sorting
		for(int j=0;j<i;j++){
			mod*=10;
			div*=10;
		}
		
		// Use a stabled sort to sort the array
		temp = countingSort(temp,size,mod,div);
	}
	
	return temp;
}
/*
 * Finds the maximum value based of it's digit
 * in a certain place
 * @param arr input array
 * @param size of the input array
 * @param mod the targeted place for the digit
 * @param div helper value to get the digit by itself
*/
int maxValue(int arr [], int size, int mod, int div){

	int max = (arr[0]%mod)/div;
	
	for(int i=0; i<size; i++) {
		int value = (arr[i]%mod)/div;
		cout<<value<<endl;
		if(max < value) max = value;
	}
	
	return max;
}

// Stable Sorting Algorithm
int* countingSort(int arr [], int size, int mod, int div) {
	// Find the maximum value of the array
	int k = maxValue(arr,size,mod,div);
	cout<<k<<endl;
	//Create your helper arrays
	int* C = new int[k+1];
	int* B = new int[size];
	
	//Set all of the values in array C equal to 0
	for(int i=0;i<k+1;i++) C[i] = 0;
	
	//Array C contains how many times a certain number has occured
	for(int i=0;i<size;i++) C[(arr[i]%mod)/div] += 1;
	
	//Array C contains all of number of elements that is less than or equal to i
	for(int i=1;i<k+1;i++) C[i] += C[i-1];
	
	//Sort the values
	for(int i=size-1;i>=0;i--){
		int value = arr[i];
		B[C[(arr[i]%mod)/div]-1] = value;
		C[(arr[i]%mod)/div] -= 1;
	}
	
	delete C;
	
	return B;
}

int main() {
	int array [] = {329,457,657,839,436,720,355};
	cout<<"Unsorted Array"<<endl;
	for(int i =0; i<7; i++) cout<< array[i] <<" ";
	cout<<endl;
	int *sortedArray = radixSort(array,7,3);
	cout<<"Sorted Array"<<endl;
	for(int i =0; i<7; i++) cout<< sortedArray[i] <<" ";
}
