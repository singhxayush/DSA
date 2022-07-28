///// FIBONACCI /////

#include<bits/stdc++.h>
using namespace std;
#define soa(x) sizeof(x)/sizeof(x[0])

int fibbo(int n, vector<int> &dp)
{
   if(n<=1) return n;

   if(dp[n] != -1) return dp[n];

   return dp[n] = fibbo(n-1, dp) + fibbo(n-2, dp);
}

int main()
{
   #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   #endif

   int n; cin>>n;
   vector<int> dp(n+1, -1);

   cout<<fibbo(n, dp);
}