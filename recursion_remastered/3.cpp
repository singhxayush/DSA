// Tower of Hanoi

#include<iostream>
using namespace std;

typedef long long  ll;

static int move_counts = 0;

void toh(int N, int a, int b, int c) // c -> destination, >
{   
    move_counts++;
    if(N==1)
    {
        // cout<<a<<c<<" ";
        cout<<"move "<<N<<" from "<<a<<" to "<<b<<endl;
        return;
    }
    toh(N-1, a, c, b);
    // cout<<a<<c<<" ";
    cout<<"move "<<N<<" from "<<a<<" to "<<b<<endl;
    toh(N-1, b, a, c);
}
int main()
{
    int N; cout<<"Enter Number of Discs :"; cin>>N;

    toh(N, 1, 2, 3);
    cout<<"\nTotal number of moves :"<<move_counts<<endl;
}