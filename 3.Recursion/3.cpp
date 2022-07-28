// Rope cutting problem

#include<iostream>
using namespace std;

typedef long long  ll;
#define ip(x) ll x; cin >> x;
#define tc int tt; cin>>tt; while(tt--)

ll maxpieces(ll n, ll a, ll b, ll c)
{
    if(n==0) return 0;
    if(n<0) return -1;
    ll res =0;
    res = max(maxpieces(n-a, a, b, c), maxpieces(n-b, a, b, c));
    res = max(res, maxpieces(n-c, a, b, c));
    if(res==-1) return -1;
    return res + 1;
}
int main(){
    ll n, a, b, c; cin>>n>>a>>b>>c;
    cout<<maxpieces(n, a, b, c);
}