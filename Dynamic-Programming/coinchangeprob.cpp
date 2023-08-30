#include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

int min_coins(vector<int> &coins, int amt, vector<int> dp) {

    if (amt < 0)
        return -1;
    if (amt == 0)
        return 0;
    if (dp[amt] != -2)
        return dp[amt];

    int coins_used = INT_MAX; bool isPossible = false;
    for (auto &coin: coins) {
        int coins_used_if_possible = min_coins(coins, amt - coin, dp);

        if (coins_used_if_possible != -1) {
            coins_used = min(coins_used, coins_used_if_possible + 1);
            isPossible = true;
        }
    }

    if (isPossible)
        return dp[amt] = coins_used;
    else
        return dp[amt] = -1;
}

int main(){

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
    #endif

    int n; cin >> n;
    vector<int> coins(n);
    for (auto &coin: coins) 
        cin >> coin;
    
    int amt; cin >> amt;

    vector<int> dp(amt + 10, -2);

    cout << min_coins(coins, amt, dp) << endl;    

    return 0;
}