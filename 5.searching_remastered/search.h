#include<bits/stdc++.h>
using namespace std;

int first_index(int a[], int n, int x) // sorted array - O(lon N) | O(1)
{
    int l = 0, h = n-1, m;
    while(l<=h)
    {
        m = (l+h)/2;
        if(a[m] > x) h = m-1;
        else if(a[m] < x) l = m+1;
        else
        {
            if(m==0 || a[m-1]!=a[m]) return m;
            else h = m-1;
        }
    }
    if(a[m]!=x) return -1;
    return m;
}

int last_index(int a[], int n, int x) // sorted array - O(lon N) | O(1)
{
    int l = 0, h = n-1, m;
    while(l<=h)
    {
        m = (l+h)/2;
        if(a[m] > x) h = m-1;
        else if(a[m] < x) l = m+1;
        else
        {
            if(m==n-1 || a[m+1]!=a[m]) return m;
            else l = m+1;
        }
    }
    if(a[m]!=x) return -1;
    return m;
}

int frequency_in_sorted(int a[], int n, int x) // O(log N) | O(1)
{
    int l = last_index(a, n, x);
    if(l==-1) return -1;
    int r = first_index(a, n, x);
    if(r==-1) return -1;
    return (l-r+1);
}

// float sqrt(int n)
// {

// }

int searh_in_infinite_array(int a[], int n, int x)
{
    int r = 1, l = 0, mid;
    while(r<n && a[r]<x) r*=2;
    if(a[r]==x) return r;
    l = r/2;
    while (l <= r)
    {
		mid = (l + r) / 2; if (a[mid] == x) return mid;
		else if (a[mid] > x) r = mid - 1;
		else if(a[mid] < x) l = mid + 1;
	}
	return -1;
}

int rotated_sorted_array(int a[], int n)
{
    int l = 0, h = n-1, m;
    while(l<=h)
    {
        m = (l+h)/2;
        int next = (m+1)%n;
        int prev = (m+n-1)%n;
        if(a[prev]>a[m] && a[next]<=a[m]) return m;
        else if(a[l]<=a[m]) l = m+1;
        else h = m-1;
    }
    return m;
}