// Making an array Unique -> my approach !!! (whatever may be input, always prints in a sorted way!)
#include<iostream>
#include<algorithm>
using namespace std;

void make_unique(int a[], int n)
{
    int i=0;
    int l = *max_element(a, a+n);
    int arr[l+1] = {0};
    for(i=0; i<n; i++) arr[a[i]]++;

    for(i=0; i<l+1; i++) if(arr[i]) cout<<i<<" ";
}
typedef long long  ll;
int main(){
    int n; cin>>n;
    int a[n];
    for(auto & elm : a)cin>>elm;

    make_unique(a, n);
}