//// insertion sort ////

#include<iostream>
#include<time.h>
#include<iomanip>
using namespace std;

void insertion_sort(int a[], int n)
{
    int i, j, key;
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

}
int main(){
    int a[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(a)/sizeof(a[0]);
    // cout<<n;
    time_t start, end;
    time(&start);
    insertion_sort(a, n);
    for(int i=0; i<n; i++) cout<<a[i]<<" ";
    time(&end);

    // double time_taken = double(end - start);
    // cout << "Time taken by program is : " << fixed
    //  << time_taken << setprecision(5);
    // cout << " sec " << endl;
}