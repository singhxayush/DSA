#include<bits/stdc++.h>
using namespace std;
#define pr(x) cout<<(x)<<endl;
#define  dbg(x) cout<<'d'<<'b'<<'g'<<'-'<<'>'<<x<<endl;
int main()
{
    int n = 10;
    int a[n] = {1, 2, 2, 1, 7, 1, 6, 6, 7, 7};
    int x = 0;
    for(int i : a) x^=i;
    x = x&(~(x-1));
    int res1 = 0, res2 = 0;
    for(int i=0; i<n; i++)
    if((a[i]&x)) res1=res1^a[i];
    else res2^=a[i];
    cout<<res1<<" "<<res2<<"\n";
}