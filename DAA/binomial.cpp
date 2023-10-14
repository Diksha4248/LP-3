#include<bits/stdc++.h>
using namespace std;

int binomial(int n,int k){

    if(n==0 || k>n) return 0;
    if(k==0 || k==n) return 1;
    return binomial(n-1,k-1)+ binomial(n-1,k);
}

// Time Complexity: O(n*k) 
// Auxiliary Space: O(n*k)

int binomialCoeff(int n, int k)
{
    int C[n + 1][k + 1];
    int i, j;
 
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= min(i, k); j++)    //min(i,k) because we don't need any value k greater than n (here n is i in each interation)
        {
            if (j == 0 || j == i)
                C[i][j] = 1;
            else
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
 
    return C[n][k];
}

int main()
{
    int n,k;
    cin>>n>>k;
    cout<<binomial(n,k);
    cout<<binomialCoeff(n,k); //using DP
    return 0;
}