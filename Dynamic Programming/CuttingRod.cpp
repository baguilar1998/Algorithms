#include <iostream>
#include <algorithm>
using namespace std;

int cut_rod(int p [], int n);
int memoized_cut_rod(int p [],int n);
int memoized_cut_rod_aux(int p [],int n,int r[]);
int bottom_up_cut_rod(int p [], int n);

/**
* A top down solution of the cutting
* rod problem that does not use dynamic
* programming
* @param p prices of each rod 
* @param n the size of the rod 
**/
int cut_rod(int p[], int n) {
	if (n==0)
		return p[0];
	int q = -1;
	for(int i=1;i<=n;i++) 
		q = max(q,p[i]+cut_rod(p,n-i));
	return q;
}

/**
* Sets up the memoized table for
* cutting rod problem
* @param p prices of each rod 
* @param n the size of the rod 
**/
int memoized_cut_rod(int p [],int n) {
	int* r = new int[n+1];
	for(int i=0;i<=n;i++)
		r[i] = -1;
	int price = memoized_cut_rod_aux(p,n,r);
	delete r;
	return price;
}

/**
* A top down solution of the cutting
* rod problem that uses dynamic programming
* @param p prices of each rod 
* @param n the size of the rod
* @param r memoized solutions 
**/
int memoized_cut_rod_aux(int p [],int n,int r[]) {
	if (r[n] >= 0)
		return r[n];
	int q = -1;
	if (n == 0) {
		q = 0;
	} else {
		for(int i=1;i<=n;i++)
			q = max(q,p[i]+memoized_cut_rod_aux(p,n-i,r));
	}
	r[n] = q;
	return q;
}
/**
* A bottom-up solution of the cutting
* rod problem that uses dynamic programming
* @param p prices of each rod 
* @param n the size of the rod 
**/
int bottom_up_cut_rod(int p[],int n) {
	int* r = new int[n+1];
	r[0] = 0;
	for(int j=1;j<=n;j++) {
		int q = -1;
		for (int i=1;i<=j;i++)
			q = max(q,p[i]+r[j-i]);
		r[j] = q;
	}
	int price = r[n];
	delete r;
	return price;
}
int main(){
	int prices [] = {0,1,5,8,9,10,17,17,20,24,30};
	cout<<"The price for a rod with length 5 is "<<bottom_up_cut_rod(prices,5)<<endl;
}
