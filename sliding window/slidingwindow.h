#include <bits/stdc++.h>
using namespace std;

#define sz(x) (sizeof(x)/sizeof(x[0]))
#define pr(x) cout<<x<<endl;
#define pr2(x, y) cout<<x<<' '<<y<<endl;
#define pr3(x, y, z) cout<<x<<' '<<y<<' '<<z<<endl;

/*
!    Slding Window
*    1. fixed size window
*    2. variable size window

!    Problems(involves array and strings mainly)
    
!    FIXED SIZE :
*    1. max and min of sub array of size K
*    2. 1st -ve in every window size of K
*    3. count occurance of anagram
*    4. max of all sub array of size K
*    5. max of min of every window size

!    VARIABLE SIZE :
*    1. Largest sub array of sum K
*    2. Largest sub string with K distinct characters
*    3. Largest of largest substring with no repeating character
*    4. Pick TOY
*    5. Min window substring
*/

int Maximum_Sum_Subarray_of_size_K(int n, int a[], int k)
{
    int res = INT_MIN, s = 0, l = 0, r = 0;
    while(r<n)
    {
        if(r-l+1 < k) s += a[r++];
        else
        {
            s += a[r++];
            res = max(res, s);
            // cout<<l+1<<" "<<r<<" "<<s<<"\n";
            s -= a[l++];
        }
    }
    res = max(res, s);
    return res;
}

void First_Negative_Number_in_every_Window_of_Size_K(int n, int a[], int k)
{
    for(int i=0; i<n; i++) cout<<a[i]<<"\t"; cout<<"\n\n";
    list<int> s;
    int l = 0, r = 0;
    while(r<n)
    {
        if(r-l+1 < k)
        {
            if(a[r] < 0) s.push_back(a[r]);
            r++;
        }
        else
        {

            if(a[r] < 0) s.push_back(a[r]);
            cout<<"l : "<<a[l]<<"\t"<<" | r : "<<a[r]<<"\t";
            if(s.empty()) cout<<0<<"\n";
            else cout<<s.front()<<"\n";
            if(a[l] < 0) s.pop_front(); 
            l++, r++;
        }
    }
}

int Count_Occurrences_Of_Anagrams(int n, int a[], int k)
{
    
}