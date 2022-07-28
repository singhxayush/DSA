///// count distinct elements /////

#include<bits/stdc++.h>
using namespace std;

int main()
{
   int a[] = {1, 3, 1, 5, 4, 6, 7, 4};
   int n = sizeof(a)/sizeof(int);
   
   unordered_set<int> s;
   for(int i=0; i<n; i++) if(s.find(a[i])==s.end()) s.insert(a[i]);
   cout<<s.size()<<endl;
}