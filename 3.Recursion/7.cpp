// NUMBER OF SUBSETS WITH SUM = X

#include<iostream>
using namespace std;

typedef long long  ll;

int subsetsum(int n, int arr[], int sum){
    if(n==0) return(sum==0) ? 1 : 0;
    return subsetsum(n-1, arr, sum) + subsetsum(n-1, arr, sum - arr[n-1]);
}
int main(){
    int n, sum; cin>>n>>sum;
    int arr[n]; for(auto & elm : arr) cin>>elm;
    cout<<subsetsum(n, arr, sum);

}