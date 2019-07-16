#include <iostream>
using namespace std;

void bottom_up_matrix_chain_order(int p [], int **m, int **s);
void print_optimal_parens(int **s, int i, int j);
	

void bottom_up_matrix_chain_order(int p [], int **m, int **s,int n) {
	n = n-1;
	for(int i=1;i<=n;i++)
		m[i][i] = 0;
	for(int l=2;l<=n;l++) {
		for(int i=1;i<=(n-l+1);i++) {
			int j = i+l-1;
			m[i][j] = INT_MAX;
			for(int k=i;k<j;k++) {
				int q = m[i][k] + m[k+1][j] + (p[i-1]*p[k]*p[j]);
				if(q < m[i][j]) {
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}
}

void print_optimal_parens(int **s, int i, int j) {
	if (i==j)
		cout<<"A"<<i;
	else {
		cout<<"(";
		print_optimal_parens(s,i,s[i][j]);
		cout<<" ";
		print_optimal_parens(s,s[i][j]+1,j);
		cout<<")";
	}
}

int main() {
	int dimensions [] = {30,35,15,5,10,20,25};
	int **m = new int*[7];
	int **s = new int*[7];
	for(int i=0;i<7;i++) {
		m[i] = new int[7];
		s[i] = new int[7];
	}
	bottom_up_matrix_chain_order(dimensions,m,s,7);
	print_optimal_parens(s,1,6);
	for(int i=0;i<7;i++) {
		delete m[i];
		delete s[i];
	}
	delete m;
	delete s;
}

