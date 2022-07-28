///// PARTITIONS : NAIVE(stable) /////

#include<bits/stdc++.h>
using namespace std;

int partition(int a[], int l, int h, int p)
{
    int temp[h-l+1], index = 0;
    for(int i = l; i < h+1; i++) if(a[i]<a[p]) { temp[index] = a[i]; index++; }
    for(int i = l; i < h+1; i++) if(a[i]==a[p]) { temp[index] = a[i]; index++; }
    int res = l+index-1;
    for(int i = l; i < h+1; i++) if(a[i]>a[p]) { temp[index] = a[i]; index++; }
    for(int i = l; i < h + 1; i++) a[i] = temp[i-l];
    return res;
}
int main()
{
    int a[] = {5, 3, 12, 8, 5, 2};
    int n = sizeof(a)/sizeof(a[0]);
    int p; cin>>p;
    int l = 0, h = n-1;
    cout<<partition(a, l, h, p)<<endl;
    for(int elm : a) cout<<elm<<" "; cout<<endl;
}