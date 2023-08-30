#include <bits/stdc++.h>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

map<pair<int, int>, int> dp;

int numWaysCoinChange(vector<int> &coins, int idx, int V) {

    // if the value is 0 I can make it in 1 way
    if (V == 0)
        return 1;
    // if the value is < 0 I can not make it 0 way
    if (V < 0)
        return 0;
    // if the coins are exhausted I can make it in 0 way
    if (idx == coins.size())
        return 0;

    if (dp.find(make_pair(idx, V)) != dp.end())
        return dp[make_pair(idx, V)];

    int numWays = 0; // stores the answer
        
    int coin = coins[idx];

    // if we choose the first coin then how many ways are there?
    int numWithCoin = numWaysCoinChange(coins, idx, V - coin);

    // if we do not choose the first coin then how many ways are there?
    int numWithoutCoin = numWaysCoinChange(coins, idx + 1, V);

    numWays += numWithCoin;
    numWays += numWithoutCoin;

    return dp[make_pair(idx, V)] = numWays;
}

int main(){

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
    #endif

    // input the coins array
    int n; cin >> n;
    vector<int> coins(n);
    for (auto &coin: coins) 
        cin >> coin;

    // input the value
    int V; cin >> V;

    cout << numWaysCoinChange(coins, 0, V) << endl;

    return 0;
}