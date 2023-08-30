#include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

const int N = 1e3+2;

long long dp[N];

long long fib(int n) {
    if (n == 0 | n == 1)
        return 0;
    if (n == 2)
        return 1;
    
    if (dp[n] != -(long long)1)
        return dp[n];
        
    dp[n] = fib(n-1) + fib(n-2);

    return dp[n];
}

int main(){

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
    #endif

    int n; cin >> n;

    for (int i = 0; i < N; i++)
        dp[i] = -1;

    cout << fib(n) << endl;

    return 0;
}