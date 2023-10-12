// 0/1 knapsack problem using dynamic programming

#include<iostream>
using namespace std;

// Time Complexity : O(n*W)
const int N = 1e5+2;
int profit[N], weights[N];

int knapsack_dp(int n, int W){
    if(n<=0) 
        return 0;

    if(W<=0) 
        return 0;

    if(weights[n-1]>W){
        return knapsack_dp(n-1,W);
    }

    return max(knapsack_dp(n-1,W), knapsack_dp(n-1,W-weights[n-1]) + profit[n-1]);
}


int main(){
    int n, W;
    cout<<"Enter number of elements : ";
    cin>>n;  //number of items in array
    cout<<"Enter Knapsack Capacity : ";
    cin>>W;  // Weight of the knapsack

    cout<<"Enter profits of each item : ";
    for(int i=0;i<n;i++){
        cin>>profit[i];
    }

    cout<<"Enter their respetive weight : ";
    for(int i=0;i<n;i++){
        cin>>weights[i];
    }

    cout<<knapsack_dp(n,W);
    return 0;
}