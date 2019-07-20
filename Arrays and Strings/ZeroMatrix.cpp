#include <iostream>
#include <vector>
using namespace std;

void zero_matrix(int **arr,int m,int n); 
void make_zero(int **arr, int row, int col,int m, int n);

struct index {
	int row;
	int col;
};

void zero_matrix(int **arr,int m,int n) {
	vector<index> indices;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++) {
			if(arr[i][j] == 0){
				index new_index;
				new_index.row = i;
				new_index.col = j;
				indices.push_back(new_index);
			}	
		}
	}
	
	for(vector<index>::iterator it = indices.begin(); it!=indices.end(); it++)
		make_zero(arr,(*it).row, (*it).col,m,n);
}

void make_zero(int **arr, int row, int col,int m, int n) {
	for(int i=0;i<n;i++) {
		arr[row][i] = 0;
	}
	for(int j=0;j<m;j++) {
		arr[j][col] = 0;
	}
}

void print_2d_array(int **arr, int m, int n) {
	for(int i=0;i<m;i++) {
		for(int j=0;j<n;j++) {
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main() {
	int **arr = new int*[3];
	for(int i=0;i<3;i++) {
		arr[i] = new int[3];
	}
	for(int i=0;i<3;i++) {
		for(int j=0;j<3;j++){
			if(i == 0 && j ==1)
				arr[i][j]=0;
			else
				arr[i][j]=1;
		}
	}
	print_2d_array(arr,3,3);
	cout<<endl;
	zero_matrix(arr,3,3);
	print_2d_array(arr,3,3);
}
