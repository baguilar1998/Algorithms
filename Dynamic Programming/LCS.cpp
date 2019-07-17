#include <iostream>
using namespace std;

void lcs_length(char X[], char Y[], int x_length, int y_length);
void print_lcs(char X[], int i, int j);
static int **c= new int*[8];
static char **b = new char*[8];

void lcs_length(char X[], char Y[], int x_length, int y_length) {
	for(int i=0;i<=x_length;i++)
		c[i][0] = 0;
	for(int j=0;j<=y_length;j++)
		c[0][j]=0;
	for(int i=0;i<x_length;i++) {
		for(int j=0;j<=y_length;j++) {
			if(X[i] == Y[j]) {
				c[i+1][j+1] = c[i][j]+1;
				b[i+1][j+1] = 'D';
			} else if(c[i][j+1] >= c[i+1][j]) {
				c[i+1][j+1] = c[i][j+1];
				b[i+1][j+1] = 'U';
			} else {
				c[i+1][j+1] = c[i+1][j];
				b[i+1][j+1] ='L';
			}
		}
	}
}

void print_lcs(char X[], int i, int j) {
	if(i == 0 || j == 0)
		return;
	if (b[i][j] == 'D') {
		print_lcs(X,i-1,j-1);
		cout<<X[i-1];
	} else if (b[i][j] == 'U') {
		print_lcs(X,i-1,j);
	} else {
		print_lcs(X,i,j-1);
	}
}

int main(){
	char X[]={'A','B','C','B','D','A','B'};
	char Y[]={'B','D','C','A','B','A'};
	for(int i=0;i<8;i++){
		c[i] = new int[7];
		b[i] = new char[7];
	}
	lcs_length(X,Y,7,6);
	print_lcs(X,7,6);

}
