///// QUICK SORT - HOARE'S PARTITION /////

#include<bits/stdc++.h>
using namespace std;

int hoares_partition(int a[], int l, int h){

    int p = a[l]; // PIVOT - here in this approach we assume that our pivot is always the first element!
    int i = l-1, j = h+1;

    while(1)
    {
        do  i++;
        while(p > a[i]);

        do j--;
        while(p < a[j]);

        if(i >= j) break;

        swap(a[i], a[j]);

        for(int k=0; k<=h; k++) cout<<a[k]<<" "; cout<<endl; // uncomment this line to understand better
    }
    cout<<"pivot : "<<j<<endl;
    return j;
}
void q_sort(int a[], int l, int h)
{
    if(l<h)
    {
        int p = hoares_partition(a, l, h);
        q_sort(a, l, p);
        q_sort(a, p+1, h);
    }
}

int main()
{
    // int a[] = {5, 3, 12, 8, 5, 2};
    // int a[] = {10, 80, 30, 90, 40, 50, 70};
    // int a[] = {7, 6, 8, 4, 3};
    // int a[] = {7, 6, 5, 4, 3, 2, 1};
    int a[] = {8, 4, 7, 9, 3, 10, 5};

    int n = sizeof(a)/sizeof(a[0]);
    int l = 0, h = n-1;

    q_sort(a, l, h);

    cout<<"\nFINAL RESULT\n";
    for(int k=0; k<=h; k++) cout<<a[k]<<" "; cout<<endl;
}