#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n; cin>>n;
    int a[n]; for(auto & elm : a) cin>>elm;

    int res=INT32_MIN, curr_sum=0;
    for(int i=0; i<n; i++)
    {
        for(int j=i; j<n; j++)
        {
            curr_sum+= a[j];
            res = max(res, curr_sum);
        }
        curr_sum = 0;
    }
    cout << res << "\n";
}