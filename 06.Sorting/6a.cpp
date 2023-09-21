/// PARTITIONS : LOMUTO (unstable) ///

#include<bits/stdc++.h>
using namespace std;

int partition(int a[], int l, int h){

    int p = a[h]; // PIVOT - here in this approach we assume that our pivot is always the last element!
    int i = l-1, j = l;
    for(j = l; j <= h-1; j++)
    {
        if(a[j]<p)
        {
            i++;
            swap(a[i], a[j]);
        }
        // for(int k=0; k<=h; k++) cout<<a[k]<<" "; cout<<endl; // uncomment this line to understand better
    }
    swap(a[i+1], a[h]);
    // for(int k=0; k<=h; k+q+) cout<<a[k]<<" "; cout<<endl; // uncomment this line to understand better

    return (i+1);
}

int main(){

    // int a[] = {5, 3, 12, 8, 5, 2};
    // int a[] = {10, 80, 30, 90, 40, 50, 70};
    // int a[] = {7, 6, 8, 4, 3};
    int a[] = {8, 4, 7, 9, 3, 10, 5};

    int n = sizeof(a)/sizeof(a[0]);
    // int p; cin>>p;
    int l = 0, h = n-1;
    partition(a, l, h);

    for(int k=0; k<=h; k++) cout<<a[k]<<" "; cout<<endl;
}