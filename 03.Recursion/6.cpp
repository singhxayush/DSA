#include<bits/stdc++.h>
using namespace std;

typedef long long   ll;
typedef long double ld;
#define tc int tt; cin>>tt; while(tt--)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);


int jos(int n, int k)
{
    if(n==1) return 0;
    return (jos(n-1, k) + k) % n;
}

int main(){
fastio
    tc{
        int n, k; cin>>n>>k;
        cout<<jos(n, k);
    }
}