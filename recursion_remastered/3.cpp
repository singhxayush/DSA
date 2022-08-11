#include<iostream>
using namespace std;

typedef long long  ll;

static int move_counts = 0;

void toh(int N, char a, char b, char c, int n) // c -> destination, >
{   
    move_counts++;
    if(N==1)
    {
        cout<<a<<c<<" ";
        return;
    }
    toh(N-1, a, c, b, n);
    cout<<a<<c<<" ";
    toh(N-1, b, a, c, n);
}
int main()
{
    int N; cout<<"Enter Number of Discs :"; cin>>N;
    int n; cin>>n;

    toh(N, 'a', 'b', 'c', n);
    cout<<"\nTotal number of moves :"<<move_counts<<endl;
}