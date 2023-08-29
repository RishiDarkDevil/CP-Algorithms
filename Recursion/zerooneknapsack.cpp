#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int knapsack(int value[], int wt[], int n, int W) {

    if (W < 0)
        return INT_MIN;
    if (n == 0 || W == 0)
        return 0;
    
    return max(
        value[n-1] + knapsack(value, wt, n-1, W-wt[n-1]), 
        knapsack(value, wt, n-1, W)
        );
}

int main(){

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
    #endif

    int n; cin >> n;
    int value[n];
    for (int i = 0; i < n; i++) 
        cin >> value[i];
    
    int weight[n];
    for (int i = 0; i < n; i++) 
        cin >> weight[i];

    int W; cin >> W;

    cout << knapsack(value, weight, n, W);

    return 0;
}