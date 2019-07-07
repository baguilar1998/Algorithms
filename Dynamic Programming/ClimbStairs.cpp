#include <iostream>
using namespace std;

int climbStairs(int n, int memo[]) {
    if(n <= 1)
        return 1;
    if(memo[n] >= 0)
        return memo[n];
    memo[n] = climbStairs(n-1, memo) + climbStairs(n-2,memo);
    return memo[n];
}
    
int climbStairs(int n) {
    int* memo = new int[n+1]; 
    for(int i=0;i<=n;i++)
        memo[i] = -1;
    int maxSteps = climbStairs(n,memo);
    delete memo;
    return maxSteps;
}

int main() {
	cout<<climbStairs(2)<<endl;
}
