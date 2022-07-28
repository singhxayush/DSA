#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int bsearch(vector<int> a, int n, int x)
{
    
    int low, high;

    low = 0; high = n-1;
    while(low<=high)
    {
        int mid = (low + high)/2;

        if(a[mid] == x) return mid;

        else if(a[mid]>x) high = mid - 1;

        else low = mid + 1;
    }

    return -1;
}
int main(){
    int n, x; cin>>n>>x;
    int i=0;
    vector<pair<int, int>> a(n);
    for(auto & elm : a){
        cin>>elm.first;
        elm.second = i;
        i++;
    }


    sort(a.begin(), a.end());
    vector<int> :: iterator it;
    it = a.begin();
    cout<<bsearch(a, n, x)<<endl;
}