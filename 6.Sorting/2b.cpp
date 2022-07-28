//// MERGE TWO ARRAY - O(N) APPROACH ////

#include<iostream>
using namespace std;

void merge(int left[], int right[], int m, int n){
    
	int arr[m+n];
    int i=0,j=0,k=m+1, c=0;
    while(i<m && j<n){
        if(left[i]<=right[j])
            arr[c++]=left[i++];
        else
            arr[c++]=right[j++];
    }
    while(i<m)
        arr[c++]=left[i++];
    while(j<n)
        arr[c++]=right[j++];    

	for(auto & elm : arr) cout<<elm<<" ";
}

int main()
{

	// int a[] = {4, 11, 44, 51, 100};
	// int b[] = {1, 5, 81};

	int a[] = {1, 1, 3, 2, 2};
	int b[] = {3, 4, 4};

	int m = sizeof(a)/sizeof(a[0]), n = sizeof(b)/sizeof(b[0]);
	merge(a, b, m, n);

	/*
	int arr[m+n], c = 0, i = 0, j = 0;      //my garbage code( fix it someday ) ( wasnt able to find the bug actually )
	while(c<=m+n)
	{
		if(b[j]<a[i] && j<=m) arr[c] = b[j++];
		else if(b[j]>=a[i] && i<=n) arr[c] = a[i++];
		cout<<arr[c]<<" "<<c<<" "<<i<<"(i) "<<j<<"(j) \n";
		if(i==n) i--;
		if(j==m) j--;
		c++;
	} */
	// for(int elm : arr) cout<<elm<<" ";
	
}