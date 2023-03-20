#include <bits/stdc++.h>
using namespace std;

#define sz(x) (sizeof(x)/sizeof(x[0]))
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
// ?--------------------------------------|KNAPSACK & PROBLEMS|--------------------------------------------------------------

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

    // display
    displaydp(n, sum);

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


int target_sum(int a[], int n, int sum)
{
    return numofSubset_with_a_givenDifference(a, n, sum);
}

// ?--------------------------------------|UNBOUNDED KNAPSACK|--------------------------------------------------------------

/*
Multuple occurances of a an item is allowed in this form of knapsack!
if the item as been processed we may take it again in ubounded
only if the process is accepting, if its rejecting we aint considering it again
but in bounded once an element has been processed we aint considering it again

*  Problems
*  - rod cutting
*  - coin change I
*  - coin change II
*  - medium ribbon cut
*/


// ******* Rod cutting Problem *******
/*
  given a rod of certain length
  and 2 arrays of size N, representing lenght and corresponding price of that
  now divide to maximize profit based on given constraints

  silmilarity with knapsack bounded
  L -> W
  len[] -> wt[]
  price[] -> val[]
*/
int maxProfit_by_CuttingRods(int len[], int price[], int n, int L)
{
    // initialize
    for(int i=0; i<=n; i++) dp[i][0] = 0;
    for(int j=0; j<=L; j++) dp[0][j] = 0;

    // Implementation
    for(int i=1; i<=n; i++)
    for(int j=1; j<=L; j++)

    if(len[i-1] <= j) 
        dp[i][j] = max( price[i-1] + dp[i][j-len[i-1]], dp[i-1][j] );
    else 
        dp[i][j] = dp[i-1][j];

    // display
    displaydp(n, L);

    // return
    return dp[n][L];
}


// ******* Coin Change I Problem *******
/*
  Given an array of coins and a target sum
  Solve for combination of coin sums to generate the given target
  with a constraint to find all possible ways(which is basically no constraint)
*/
int coinChange(int coins[], int n, int sum)
{
    // initialize
    for(int i=1; i<=n; i++) dp[i][0] = 1;
    for(int j=0; j<=sum; j++) dp[0][j] = 0;

    // Implementation
    for(int i=1; i<=n; i++)
    for(int j=1; j<=sum; j++)
    if(coins[i-1] <= j) dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
    else dp[i][j] = dp[i-1][j];

    // display
    displaydp(n, sum);

    // return
    return dp[n][sum];
}


// ******* Coin Change II Problem ******* (NOT COMPLETE YET !!!)
/*
  Given an array of coins and a target sum
  Solve for combination of coin sums to generate the given target
  with a constraint to solve it in Minimum number of coins
*/
int coinChange2(int coins[], int n, int sum)
{
    // initialize
    for(int i=1; i<=n; i++) dp[i][0] = 0;
    for(int j=0; j<=sum; j++) dp[0][j] = INT_MAX-1;
    for(int j=1; j<=sum; j++) j%coins[0] ? dp[1][j] = INT_MAX-1 : dp[1][j] = j/coins[0];

    // Implementation
    for(int i=1; i<=n; i++)
    for(int j=1; j<=sum; j++)

    if(coins[i-1] <= j)
        dp[i][j] = min(dp[i][j-coins[j]]+1, dp[i-1][j]);
    else
        dp[i][j] = dp[i-1][j];

    // display
    displaydp(n, sum);

    // return
    return dp[n][sum];
}


// ?-----------------------------|LONGEST COMMON SUBSEQUENCE - IMPORTANT|--------------------------------------------------------------

// ? MOST VARIATIONS COMES FROM THIS PROBLEM PATTERN - AROUND 15 PATTERNS

