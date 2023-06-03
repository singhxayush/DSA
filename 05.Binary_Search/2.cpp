// binary search recursive!

#include<iostream>
#include<algorithm>
using namespace std;

int b_search(int a[], int l, int h, int x){
    
    if(l>h) return -1;

    int m = (l+h)/2;

    if(a[m]==x) return m;
    else if(a[m] > x) return b_search(a, l, m-1, x);
    else return b_search(a, m+1, h, x);

}
int main(){

    int n, x; cin>>n>>x;
    int a[n];
    for(int & elm: a) cin>>elm;

    sort(a, a+n);

    cout << b_search(a, 0, n-1, x);
}