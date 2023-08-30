#include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

int main(){

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
    #endif

    int n; cin >> n;

    vector<int> dp(n+1);

    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;

    for (int i = 3; i <= n; i++) 
        dp[i] = dp[i-1] + dp[i-2];
    
    cout << dp[n] << endl;

    return 0;
}