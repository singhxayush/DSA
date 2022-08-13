// TOH - Bit Manipulation
#include<bits/stdc++.h>
using namespace std;
typedef  long long   ll;
#define pr(x) cout<<(x)<<endl;
#define ps(x) cout<<(x)<<" ";
#define  dbg(x) cout<<'d'<<'b'<<'g'<<'-'<<'>'<<x<<endl;

int main()
{
    int N; cout<<"Enter Number of Discs :"; cin>>N;
    int n; cout<<"Enter the step Number :"; cin>>n;

    ll c = 0, k, pos, p = 0, q = 0;

    vector<int> l, m, r;
    for(int i=N; i>=1; i--) l.push_back(i);
    int x = pow(2, N);
    for(int i=1; i<x; i++)
    {
        pos = ffsl(i);
        cout<<pos<<"\n";
        if(pos&1)
        {
            if(pos == l.back())
            {
                l.pop_back();
                m.push_back(pos);
                cout<<"move "<<pos<<" from "<<1<<" to "<<2<<"\n";
            }
            else if(pos == m.back())
            {
                m.pop_back();
                r.push_back(pos);
                cout<<"move "<<pos<<" from "<<2<<" to "<<3<<"\n";
            }
            else if(pos == r.back())
            {
                m.pop_back();
                l.push_back(pos);
                cout<<"move "<<pos<<" from "<<3<<" to "<<1<<"\n";
            }
        }
        else
        {
            if(pos == l.back())
            {
                l.pop_back();
                if(m.back()<pos)
                {
                    m.push_back(pos);
                    cout<<"move "<<pos<<" from "<<1<<" to "<<2<<"\n";
                }
                else
                {
                    r.push_back(pos);
                    cout<<"move "<<pos<<" from "<<1<<" to "<<3<<"\n";
                }
            }
            else if(pos == m.back())
            {
                m.pop_back();
                if(r.back()<pos)
                {
                    r.push_back(pos);
                    cout<<"move "<<pos<<" from "<<2<<" to "<<3<<"\n";
                }
                else
                {
                    l.push_back(pos);
                    cout<<"move "<<pos<<" from "<<2<<" to "<<1<<"\n";
                }
            }
            else if(pos == r.back())
            {
                r.pop_back();
                if(m.back()<pos)
                {
                    m.push_back(pos);
                    cout<<"move "<<pos<<" from "<<3<<" to "<<2<<"\n";
                }
                else
                {
                    l.push_back(pos);
                    cout<<"move "<<pos<<" from "<<3<<" to "<<1<<"\n";
                }
            }
        }
    }
}