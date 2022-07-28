#include<bits/stdc++.h>
using namespace std;

#define ip(x) int x; cin >> x;
#define tc int tt; cin>>tt; while(tt--)
int main(){
    ip(n)
    int arr[n]; for(auto & elm : arr) cin >> elm;
    vector<int> ve, vo;
    int t=0, t1=0 , t2=0;
    for(int i=0; i<n; i++){
        t ^= arr[i];
        if(arr[i]%2==0) ve.push_back(arr[i]);
        else vo.push_back(arr[i]);
    }
    // cout << t;
    t1 = t; t2 = t;
    for(int i=0; i<ve.size(); i++) t1 = t1^ve[i];
    for(int i=0; i<vo.size(); i++) t2 = t2^vo[i];
    cout << t1 <<" "<< t2;
}