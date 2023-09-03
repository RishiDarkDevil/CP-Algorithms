#include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

const int N = 1e5+2, MOD = 1e9+7;
vector<int> dp(N, -1);

int countDistinctWays(int nStairs) {
    if (nStairs < 0)
        return 0;
    if (nStairs == 0)
        return 1;
    if (dp[nStairs] != -1)
        return dp[nStairs];
    return dp[nStairs] = (countDistinctWays(nStairs-1) % MOD + countDistinctWays(nStairs-2) % MOD) % MOD;
}

int main(){

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
    #endif

    int n; cin >> n;

    cout << countDistinctWays(n) << endl;

    return 0;
}