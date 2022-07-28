///// UNORDERED MAP : same un. set theroy applies for un. maps /////

#include<bits/stdc++.h>
using namespace std;

int main()
{

    int x; cin>>x;
auto start = chrono::high_resolution_clock::now();
    cout<<x<<endl;
    cout<<123<<endl;
auto end = chrono::high_resolution_clock::now();

    double _t = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    _t *= 1e-9;
    cout << "Execution Time : " << fixed << _t << setprecision(9); cout << " s";
}