#include<iostream>
#include<vector>
using namespace std;

typedef long long  ll;
int main(){
    int n;  cin>>n;
    vector<int> v;
    while(n){
        v.push_back(n&1);
        n = n>>1;
    }
    for(int i = v.size()-1; i>=0; i--) cout<<v[i];
}