#include <iostream>
using namespace std;

int binarySearch(int arr [], int low, int high, int value, int size);

int binarySearch(int arr[], int low, int high, int value, int size) {
	if(low==high) {
		if(low >= size || low < 0) return -1;
		return low;
	}
	int mid = (low+high)/2;
	if(value <= arr[mid]) return binarySearch(arr,low,mid,value,size);
	return binarySearch(arr,mid+1,high,value,size);
}
int main(){
	int array [] = {1,2,3,4,5,6,7,8,9,10};
	int index = binarySearch(array,0,10,4,10);
	cout<<"Your value is located at index: "<<index;
}
