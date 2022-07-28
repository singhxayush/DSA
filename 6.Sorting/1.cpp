//// insertion sort ////

#include<iostream>
using namespace std;
int main(){
    int a[] = {12,2,3,54,64,4,4,2,4,5,756,56,21,3242,45,745,3442,657,1,44,42,5,6,7,8,22,54,5677,0,89,4};
    int n = sizeof(a)/sizeof(a[0]);
    int i, j, key;
    // sort(a, a+n);

    for(i=1; i<n; i++)
    {
        key = a[i];
        j = i-1;
        while(a[j] > key && j>=0)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
    for(auto & elm : a) cout<<elm<<" ";
}

// o(n^2)worstcase_when reverse sorted - in-place and stabe - o(n)best case_when sorted !!!