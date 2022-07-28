//// MERGE FUNCTION OF MERGE SORT ////

#include<iostream>
using namespace std;

void merge(int arr[], int l, int m, int h){
    
    int n1=m-l+1, n2=h-m;
    int left[n1],right[n2];

    for(int i=0;i<n1;i++) left[i]=arr[i+l];
    for(int j=0;j<n2;j++) right[j]=arr[m+1+j];    

    int i=0,j=0,k=l;

    while(i<n1 && j<n2){

        if(left[i]<=right[j]) arr[k++]=left[i++];
        else arr[k++]=right[j++];
    }
    while(i<n1) arr[k++]=left[i++];
    while(j<n2) arr[k++]=right[j++];    
}
int main()
{
	// int a[] = {4, 11, 44, 51, 100, 1, 5, 81};
	int a[] = {1, 1, 3, 2, 2, 3, 4, 4};
	
	int h = sizeof(a)/sizeof(a[0])-1;
	int m = 0, l = 0;
	for(int i=0; i<h; i++) { if(a[i+1]<a[i]) break; m++; }
	merge(a, l, m, h);
	for(int elm : a) cout<<elm<<" ";
}