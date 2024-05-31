#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

// Recursive function to count the numeber of distinct ways
// to make the sum by using n coins

int64_t count(vector<int64_t>& coins, int n, int sum,
		vector<vector<int64_t> >& dp)
{
	// Base Case
	if (sum == 0)
		return dp[n][sum] = 1;

	// If number of coins is 0 or sum is less than 0 then
	// there is no way to make the sum.
	if (n == 0 || sum < 0)
		return 0;

	// If the subproblem is previously calculated then
	// simply return the result
	if (dp[n][sum] != -1)
		return dp[n][sum];

	// Two options for the current coin
	return dp[n][sum]
		= ( count(coins, n, sum - coins[n - 1], dp)
			+ count(coins, n - 1, sum, dp) ) % MOD;
}
int32_t main()
{
    int n, sum;
    cin >> n;
    vector<int64_t> coins(n);
    for (auto& it : coins)
        cin >> it;
    cin >> sum;
    // 2d dp array to store previously calculated
    // results
    vector<vector<int64_t> > dp(n + 1,
                            vector<int64_t>(sum + 1, -1));
    int64_t res = count(coins, n, sum, dp);
    cout << res % MOD << endl;
}
