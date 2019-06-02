#include <iostream>
using namespace std;

void quicksort(int a [], int p, int r);
int partition(int a [], int p, int r);

int main() {
	int array [] = {2,8,7,1,3,5,6,4};
	quicksort(array,0,7);
	for (int i = 0; i < 8; i++)cout<<array[i]<<" ";
}

void quicksort(int a [], int p, int r) {
	if (p < r){
		int q = partition(a,p,r);
		quicksort(a,p,q-1);
		quicksort(a,q+1,r);	
	}
}

int partition(int a [], int p, int r) {
	int x = a[r];
	int i = p-1;
	for (int j = p; j <= r-1; j++ ) {
		if (a[j] <= x) {
			i = i+1;
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	int temp = a[i+1];
	a[i+1] = a[r];
	a[r] = temp;
	return i+1;
}

