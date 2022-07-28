// Finding all subsets of a string

#include<iostream>
using namespace std;

typedef long long  ll;
#define ip(x) ll x; cin >> x;
#define tc int tt; cin>>tt; while(tt--)

void subsets(string s, string empty = "", int i=0)
{
    if(i==s.length())
    {
        cout<<empty<<endl;
        return;
    }
    subsets(s, empty, i+1);
    subsets(s, empty+s[i], i+1);

}
int main(){
    string s; cin>>s;
    subsets(s);
}