//// MERGE SORT ALGORITHM ////

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

void merge_sort(int a[], int l, int r)
{
    if(r>l)
    {
        int m = l + (r-l)/2;
        merge_sort(a, l, m);
        merge_sort(a, m+1, r);
        merge(a, l, m, r);
    }
}

int main()
{
	int a[] = {1, 1, 6 ,3 , 1, 9, 3, 2, 2, 3, 5, 7, 4, 4};
	int m = sizeof(a)/sizeof(a[0]), l=0;

    merge_sort(a, l, m-1);
    for(int i=0; i<m; i++) cout<<a[i]<<" ";
}