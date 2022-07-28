#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
int main(){
    int n, i; cin>>n;
    int a[n]; for(auto & elm : a) cin>>elm;

    int res1 = a[0], max_ending = a[0];

    for(i=0; i<n; i++)
    {
        max_ending = max(max_ending+a[i], a[i]);
        res1 = max(res1, max_ending);
    }

    int res2 = INT_MIN,  min_ending = a[0];

    for(i=0; i<n; i++)
    {
        min_ending = min(min_ending+a[i], a[i]);
        res2 = min(res2, min_ending);
    }

    cout<<res2;

    // cout << max(res1, res2) << endl;
}