//// megre two sorted array ////

// naive approach : copy both the arrays into one and apply sort to the 3rd array
#include<iostream>
#include<algorithm>
using namespace std;

// void disa(int a[], int n) {for(int elm : a, a+n) cout<<elm<<" "; return; }

int main()
{
	int n = 5, m = 3;
	int a[n] = {4, 11, 44, 51, 100};
	int b[m] = {1, 5, 81};
	
	int c[n+m];
	
	for(int i=0; i<n;   i++) c[i] = a[i];
	for(int i=n; i<m+n; i++) c[i] = b[i-n];
	sort(c, c+m+n);
	for(int elm : c) cout<<elm<<" ";
}