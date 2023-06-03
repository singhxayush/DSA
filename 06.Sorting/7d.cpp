///// TAIL CALL ELIMINATION IN Q_SORT /////

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
    begin :
    if(l<h)
    {
        int p = hoares_partition(a, l, h);
        q_sort(a, l, p);
        l = p+1;
        goto begin;
    }
}
int main()
{
    
}