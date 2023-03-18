#include <bits/stdc++.h>
using namespace std;

#define pr(x) cout<<x<<endl;
#define pr2(x, y) cout<<x<<' '<<y<<endl;
#define pr3(x, y, z) cout<<x<<' '<<y<<' '<<z<<endl;


// DP matrix for Memoization 
int static dp[1000][1000];


// Normal recursive 0 - 1 Knapsack
int knapsack_recursive(int wt[], int val[], int w, int n)
{
    if(n == 0 || w == 0) return 0;

    if(wt[n-1]<= w) return max(
            val[n-1] + knapsack_recursive(wt, val, w-wt[n-1], n-1), 
            knapsack_recursive(wt, val, w, n-1)
    );
    else return knapsack_recursive(wt, val, w, n-1);
}


// Knapsack with memoization
// int knapsack_dp_memoization(int wt[], int val[], int w, int n)
// {
//     if(n == 0 || w == 0) return 0;

//     if(dp[n][w] != -1) return dp[n][w];

//     if(wt[n-1]<=w)
//     {
//         dp[n][w] = max(
//             val[n-1] + knapsack_dp_memoization(wt, val, w-wt[n-1], n-1),
//             knapsack_dp_memoization(wt, val, w, n-1)
//         );
//     }
//     else if(wt[n-1]>w) return knapsack_dp_memoization(wt, val, w, n-1);
// }


// Iterative bottom Up knapsack
int knapsack_dp_bottomup(int wt[], int val[], int w, int n)
{
    for(int i=0; i<=n; i++) dp[i][0] = 0;
    for(int j=0; j<w+1; j++) dp[0][j] = 0;

    for(int i=1; i<n+1; i++)
    for(int j=1; j<w+1; j++)
    {
        if(wt[i-1] <= j) dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]], dp[i-1][j]);
        else dp[i][j] = dp[i-1][j];
    }
    return dp[n][w];
}


////////// Knapsack based std problems(6) //////////

// SubSet Sum Problem (subset = subseq)
bool subsetsum(int a[], int n, int sum)
{
    // initialize
    for(int i=0; i<=n; i++) dp[i][0] = 1;
    for(int j=1; j<=sum; j++) dp[0][j] = 0;

    // Implementation
    for(int i=1; i<=n; i++)
    for(int j=1; j<=sum; j++)
    {
        if(a[i-1] <= j) dp[i][j] = dp[i-1][j-a[i-1]] || dp[i-1][j];
        else dp[i][j] = dp[i-1][j];
    }

    // display
    for(int i=0; i<=n; i++) { for(int j=0; j<=sum; j++) cout<<dp[i][j]<<" "; cout<<endl; }

    // return 
    return dp[n][sum];
}

// Count number of subsets for a given subset sum
int numofSubsets(int a[], int n, int sum)
{
    // initialize
    for(int i=0; i<=n; i++) dp[i][0] = 1;
    for(int j=1; j<=sum; j++) dp[0][j] = 0;

    // Implementation
    for(int i=1; i<=n; i++)
    for(int j=1; j<=sum; j++)
    if(a[i-1] <= j) dp[i][j] = dp[i-1][j] + dp[i-1][j-a[i-1]];
    else dp[i][j] = dp[i-1][j];

    // return 
    return dp[n][sum];
}


/*
  Equal sum partition - 2 equal subset sum - just return T/F
  tot sum must be even then -> find a subset for 1/2 the total sum
  if present -> another subset with same sum will must be there -> solved
*/
bool equal_partition(int a[], int n)
{
    int sum = accumulate(a, a+n, 0);
    if(sum%2) return false;
    sum /= 2;
    return subsetsum(a, n, sum);
}

