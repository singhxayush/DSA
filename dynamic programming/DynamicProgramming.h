#include <bits/stdc++.h>
using namespace std;


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
bool subsetsum(int arr[], int n, int sum)
{
    for(int i=0; i<=n; i++) dp[i][0] = 1;
    for(int j=1; j<=sum; j++) dp[0][j] = 0;

    for(int i=1; i<=n; i++)
    for(int j=1; j<=sum; j++)
    {
        if(arr[i-1] <= j) dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
        else dp[i][j] = dp[i-1][j];
    }

    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=sum; j++) cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    return dp[n][sum];
}

// Equal sum partition
