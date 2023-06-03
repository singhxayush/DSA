// Sorting ()

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void sortit(int a[], int n)
{
    vector<int> v;
    
    int i=0;
    
    int l = *max_element(a, a+n);
    
    int arr[l+1] = {0};

    for(i=0; i<n; i++) arr[a[i]]++;

    for(i=0; i<l+1; i++) if(arr[i]){
        if(arr[i]==1) v.push_back(i);
        else for(int j=0; j<arr[i]; j++) v.push_back(i); 
    }
    
    for(auto & elm : v) cout<<elm<<" ";
}
int main(){
    int n; cin>>n;
    int a[n];
    for(auto & elm : a)cin>>elm;

    sortit(a, n);
}