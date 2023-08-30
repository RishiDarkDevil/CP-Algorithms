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
    const int N = 1e5+2;
    vector<int> dp(N+2, INT_MAX);

    for (int i = 0; i < 4; i++)
        dp[i] = i;
    
    for (int num = 4; num <= n; num++) {
        for (int i = 1; i*i <= num; i++)
            dp[num] = min(dp[num], dp[num - i*i] + 1);
    }

    cout << dp[n] << endl;

    return 0;
}