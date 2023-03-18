#include <bits/stdc++.h>
using namespace std;

#define pr(x) cout<<x<<endl;
#define pr2(x, y) cout<<x<<' '<<y<<endl;
#define pr3(x, y, z) cout<<x<<' '<<y<<' '<<z<<endl;


// *DP matrix for Memoization 
int static dp[1000][1000];

void displaydp(int n, int w)
{
    cout<<"n : "<<n<<" | ";
    cout<<"W : "<<w<<"\n\n";

    for(int j=0; j<=w; j++) cout<<"\t"<<j; cout<<"\n\n";

    for(int i=0; i<=n; i++)
    {
        cout<<i<<"\t";
        for(int j=0; j<=w; j++)
        {
            cout<<dp[i][j]<<"\t";
        }
        cout<<"\n";
    }
    cout<<"\n";
}

// ******* Normal recursive 0 - 1 Knapsack *******
int knapsack_recursive(int wt[], int val[], int w, int n)
{
    if(n == 0 || w == 0) return 0;

    if(wt[n-1]<= w) return max(
            val[n-1] + knapsack_recursive(wt, val, w-wt[n-1], n-1), 
            knapsack_recursive(wt, val, w, n-1)
    );
    else return knapsack_recursive(wt, val, w, n-1);
}


// ******* Knapsack with memoization *******
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


// ******* Iterative bottom Up knapsack *******
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


// !Knapsack based std problems(6)

// ******* SubSet Sum Problem (subset = subseq) *******
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
    displaydp(n, sum);

    // return 
    return dp[n][sum];
}

// ******* Count number of subsets for a given subset sum *******
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


// *******Equal sum partition - 2 equal subset sum *******
/*
  - just returns T/F
  - tot sum must be even then -> find a subset for 1/2 the total sum
  - if present -> another subset with same sum will must be there -> solved
*/

bool equal_partition(int a[], int n)
{
    int sum = accumulate(a, a+n, 0);
    if(sum%2) return false;
    sum /= 2;
    return subsetsum(a, n, sum);
}


// ******* Minimum subset sum difference *******
/*
!PART 1 : Mathematical/Analytical redution
  - s1 and s2 are two mutually exclusive and exhaustive subsets of a given container
  - s1 + s2 = total sum = S(constant)
  - to find min abs(s2 - s1)
  - s2 = S - s1;
  ? now the problem reduces to find min abs(S - 2*s1)

!PART 2 : Code implementation reduction and DP(Bottom Up)
  - calculate possible s1 vals till S
  - implement bottom up approach as in subset sum problem
  - the last row of the matrix(dp) will represent
  - true(1) for a given possible constrained sum if it exists
  - iterate through 1/2 them and get the min difference
  - since other half are mutually exhaustive, it will repeat itself in the difference
*/

int minSubsetSumDiff(int a[], int n)
{
    // Initialize
    int sum = accumulate(a, a+n, 0);
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
    displaydp(n, sum);

    // result + return
    int res = INT_MAX;
    for(int j=0; j<=sum; j++) if(dp[n][j])
    res = min(res, abs(sum-2*j));
    return res;
}


// ******* Count The Number of Subsets With a Given Difference *******
/* 
!PART 1 : break down the complex problem in to simpler one
  - to fine 2 subset with a given difference
  - s1 - s2 = C (constant given)
  - s1 + s2 = S (constant sum of array)
  - now 2*s1 = C + S
  - s1 = (C + S)/2
  ?problem reduces to finding a number of subset with a given sum

!PART 2 : DP(bottom up) implementation
  - now find the subset with a given sum = (C + S)/2
  ?implement : numofSubsets(int a[], int n, int sum) function 
*/

int numofSubset_with_a_givenDifference(int a[], int n, int diff)
{
    // Initialize
    int s = accumulate(a, a+n, 0);
    int sum = (s + diff)/2;
    for(int i=0; i<=n; i++) dp[i][0] = 1;
    for(int j=1; j<=sum; j++) dp[0][j] = 0;

    // numofSubsets funcn Call
    return numofSubsets(a, n, sum);
}