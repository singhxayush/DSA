// binary search itterative!
// but this code will return intdex of the sorted array but not the actual array!!! see next code

#include<iostream>
#include<algorithm>
using namespace std;

int bsearch(int a[], int n, int x)
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
int main()
{

    int n, x; cin>>n>>x;
    int a[n]; for(int & elm : a) cin>>elm;

    sort(a, a+n);
    cout<<bsearch(a, n, x)<<endl;;

}