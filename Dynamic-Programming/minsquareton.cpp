#include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

const int N = 1e5 + 2;
vector<int> dp(N, -1);

int minnumsqrs(int n) {

    if (n <= 3)
        return n;

    if (dp[n] != -1)
        return dp[n];
    
    int minsqrscount = INT_MAX, minsqr = INT_MIN;
    for (int i = 1; i*i <= n; i++) {
        int num = minnumsqrs(n-i*i) + 1;
        if (minsqrscount > num) {
            minsqrscount = num;
            minsqr = i;
        }
    }
    
    dp[n] = minsqrscount;

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

    cout << minnumsqrs(n) << endl;

    return 0;
}