//check palindrome -> look for the boolean way of writing the function

#include<iostream>
#include<string>
using namespace std;

typedef long long  ll;
#define ip(x) ll x; cin >> x;
#define tc int tt; cin>>tt; while(tt--)

bool ispalindrome(string &s, int start, int end){
    if(start >= end) return true;
    return ( s[start]==s[end] && (ispalindrome(s, start+1, end-1)));
}
int main(){
    string str;
    cin>>str;
    if(ispalindrome(str, 0, str.size()-1)) cout<<1;
    else cout<<0;
}