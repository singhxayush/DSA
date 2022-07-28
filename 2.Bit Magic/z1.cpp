///// Position of 1st set bit : my solution /////

#include<bits/stdc++.h>
using namespace std;
void first_setbit(int n)
{
    if(n == 0) {cout<<0<<endl; return;}
    
    n^=(n-1); n++; n>>=1;
    n = log2(n) + 1;
    
    cout<<n<<endl;
}
int main()
{
    int n; cin>>n;
    first_setbit(n);
}