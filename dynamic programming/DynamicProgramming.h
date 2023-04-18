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
// ?---------------------------------------|KNAPSACK & PROBLEMS|--------------------------------------------------------------

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


// ******* Knapsack with memoization - Bottom Up *******
int knapsack_dp_memoization(int wt[], int val[], int w, int n)
{
    if(n == 0 || w == 0) return 0;

    if(dp[n][w] != -1) return dp[n][w];

    if(wt[n-1]<=w)
    {
        return dp[n][w] = max(
            val[n-1] + knapsack_dp_memoization(wt, val, w-wt[n-1], n-1),
            knapsack_dp_memoization(wt, val, w, n-1)
        );
    }
    else if(wt[n-1]>w) return dp[n][w] = knapsack_dp_memoization(wt, val, w, n-1);

    return 0;
}


// ******* Iterative Top Down knapsack *******
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

!PART 2 : Code implementation reduction and DP(Top Down)
  - calculate possible s1 vals till S
  - implement Top Down approach as in subset sum problem
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

!PART 2 : DP(Top Down) implementation
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

// ?----------------------------------------|UNBOUNDED KNAPSACK|--------------------------------------------------------------

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
  !given a rod of certain length
  and 2 arrays of size N, representing lenght and corresponding price of that
  now divide to maximize profit based on given constraints

  !similarity with knapsack bounded
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


// ?-------------------------------|LONGEST COMMON SUBSEQUENCE - IMPORTANT|--------------------------------------------------------------

/*
? MOST VARIATIONS COMES FROM THIS PROBLEM PATTERN - AROUND 15 PATTERNS

*  - LCS(longest common subseq)
*  - longest common substring
*  - print lcs
*  - shortest common super seq
*  - print scs
*  - minm no. is insertions and deletions a->b
*  - largest repeting subseq
*  - length of largest subseq of A which is a substring in B
*  - subseq pattern matching
*  - count how many times A appears as subsequence in B
*  - largest palindromic subseq
*  - largest palindromic substring
*  - count of palindromic substring
*  - minm no. of deletions in a string to make it a palindrome
*  - minm no. of insertions in a string to make it a palindrome
*/

// !NOTE : Recursive part is must, for both top down and bottom up

//* Recursive LCM(brute force)
/*
  !Problem statement : To Find length of LCS
  - given 2 stings
  - s1 = abcdgh
  - s2 = abedfhr
  - lcs(s1, s2) = ab..d..h (abdh)
  - So output = 4

  !Implementing Recursive approach : think of the smallest valid i/p
  steps :
  - base condtn
  - choice diag
  - IP - small
*/
int LCS_recursive(string s1, string s2, int n, int m)
{
    // Base
    if(!n || !m) return 0;

    // choice making recursive call
    if(s1[n-1] == s2[m-1]) return
        1 + LCS_recursive(s1, s2, n-1, m-1);
    else return
        max( LCS_recursive(s1, s2, n, m-1), LCS_recursive(s1, s2, n-1, m) );
}


//* Memoization of LCS
// since recurive calls have sub problems, now we approach with bottom up(memoization)
int LCS_bottomUp(string s1, string s2, int n, int m)
{
    // Base
    if(!n || !m) return 0;

    // choice makinng recursion and DP sub problem
    if(dp[n][m] != -1) return dp[n][m];

    if(s1[n-1] == s2[m-1]) return
        dp[n][m] = 1 + LCS_bottomUp(s1, s2, n-1, m-1);
    else return
        dp[n][m] = max( LCS_bottomUp(s1, s2, n, m-1), LCS_bottomUp(s1, s2, n-1, m) );
}


//* Top Down LCS



// ?-------------------------------|MATRIX CHAIN MULTIPLICATION|--------------------------------------------------------------
int mcm_recursive(int a[], int i, int j)
{
    if(i>=j) return 0;
    int res = INT_MAX;
    for(int k=i; k<j; k++)
    {
        int temp = mcm_recursive(a, i, k) + mcm_recursive(a, k+1, j) + a[i]*a[k]*a[j];
        res = min(res, temp);
    }
    return res;
}

int mcm_bottom_up(int a[], int i, int j)
{
    
}