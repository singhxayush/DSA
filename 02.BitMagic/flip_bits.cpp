#include<bits/stdc++.h>
using namespace std;

#define flipBits(n,b) ((n)^((1u<<(b))-1))

void dectobi(int n){
    vector<int> v;
    while(n){
        cout<<1;
        v.push_back(n&1);
        n = n>>1;
    }
    for(int i = v.size()-1; i>=0; i--) cout<<v[i];
}
typedef long long  ll;
int main(){
    int n, a=0, b=1;
    cin>>n;
    // int l = log2(n)+1;

    cout<<n<<" "; dectobi(n);
    // cout<<"\n"<<flipBits(n, l)<<" "; dectobi(flipBits(n, l));

    // cout<<n+flipBits(n,l)+1<<endl;

    // while(cin >> n)
    // if(n&1) cout<<(n ^ a)<<endl;
    // else cout<<(n ^ b)<<endl;
}