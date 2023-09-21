///// PARTITIONS : HOARE'S (also unstabe but works better than lomuto partition but same complextiy) /////
// here we consider first element as pivot

#include<bits/stdc++.h>
using namespace std;

int partition(int a[], int l, int h){

    int p = a[l]; // PIVOT - here in this approach we assume that our pivot is always the first element!
    int i = l-1, j = h+1;

    for(int k=0; k<=h; k++) cout<<a[k]<<" "; cout<<endl; // uncomment this line to understand better

    while(1)
    {
        do i++;
        while (p > a[i]);

        do j--; 
        while(p < a[j]);

        if(i >= j) break;

        swap(a[i], a[j]);

        for(int k=0; k<=h; k++) cout<<a[k]<<" "; cout<<endl; // uncomment this line to understand better
    }
    // cout<<"PIVOT INDEX IS : "<<j<<"\nFinal Arrangement :";
    return j;
}

int main()
{
    // int a[] = {5, 3, 12, 8, 5, 2};
    // int a[] = {10, 80, 30, 90, 40, 50, 70};
    int a[] = {8, 4, 7, 9, 3, 10, 5};
    int n = sizeof(a)/sizeof(a[0]);
    // int p; cin>>p;
    
    int l = 0, h = n-1;

    partition(a, l, h);
    for(int k=0; k<=h; k++) cout<<a[k]<<" "; cout<<endl;
}