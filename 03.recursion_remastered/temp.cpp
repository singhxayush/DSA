// 
#include<bits/stdc++.h>
using namespace std;
#define pr(x) cout<<(x)<<endl;
#define  dbg(x) cout<<'d'<<'b'<<'g'<<'-'<<'>'<<x<<endl;

void insert(int a[], int top, int k)
{
    if(top==0)
    {
        a[top] = k;
        return;
    }
    if(a[top-1]<=k)
    {
        a[top] = k;
        return;
    }
    int val = a[top-1];
    insert(a, top-1, k);
    a[top+1] = val;
    return;
}

int main()
{
    int a[] = {2, 1};
    int n = sizeof(a)/sizeof(a[0]);
    int top = n-1;
    int k = a[top];
    insert(a, top, k);
    for(int i=0; i<n; i++) cout<<a[i]<<" ";
}

