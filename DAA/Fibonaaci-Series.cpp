#include <bits/stdc++.h>
using namespace std;

// iterative approach
// Time Complexity: O(n) 
// Auxiliary Space: O(1)
int fib(int n)
{
	int a = 0, b = 1, c, i;
	if (n == 0)
		return 0;
	if (n==1) return 1;
	for (i = 2; i <= n; i++) {
		c = a + b;
		a = b;
		b = c;
	}
	return b;
}

// Recusive approach
// Time Complexity: O(2^n)
// Auxiliary Space: O(n), For recursion call stack.
int fibonacci_numbers(int n) 
{ 
    if(n == 0){ 
        return 0; 
    } 
    else if(n == 1){ 
        return 1; 
    } 
    else{ 
        return fibonacci_numbers(n-2) + fibonacci_numbers(n-1); 
    } 
} 

int main()
{
	int n;
    cin>>n;
	for(int i=0;i<n;i++){
		cout<<fib(i)<<" ";  //cout<<fibonacci_numbers(i);
	}
	
	return 0;
}

