// MATRIX PATHS - DSA ONE(9)

#include<iostream>
#include<algorithm>
using namespace std;

float matrix_paths(int n, int m)
{
    if(n==1 || m==1)
    {
        if(n==1 && m!=1) return m;
        if(m==1 && n!=1) return n;
    }
    return 1 + (matrix_paths(n-1, m) + matrix_paths(n, m-1));
}
int main(){
    int n, m; cin>>n>>m;
    cout<<matrix_paths(n, m);
}