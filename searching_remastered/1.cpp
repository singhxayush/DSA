#include<bits/stdc++.h>
#include"search.h"
using namespace std;
#define pr(x) cout<<(x)<<endl;
#define  dbg(x) cout<<'d'<<'b'<<'g'<<'-'<<'>'<<x<<endl;
#define soa(x) sizeof(x)/sizeof(x[0])

int main()
{
    // int a[] = {1, 2, 3, 4, 4, 5, 6, 7};
    // int a[] = {1, 3, 5, 5, 5, 5, 67, 123, 125};
    // for(int i=0; i<10000; i++) cout<<2*i<<" ";
    // int a[10000];
    // for(int & x : a) cin>>x;
    int a[7] = {4, 5, 6, 7, 1, 2, 3}; // rotated sorted array

    // int n = soa(a);
    // cout<<first_index(a, n, 5);
    // cout<<last_index(a, n, 5);
    // cout<<frequency_in_sorted(a, n, 5);
    // if(a[100]) cout<<123;
    // cout<<searh_in_infinite_array(a, 10000, 100);
    cout<<rotated_sorted_array(a, 7);
}