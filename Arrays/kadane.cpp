#include <bits/stdc++.h>
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
    int arr[n];
    for (int i = 0; i < n; i++) 
        cin >> arr[i];
    
    int currentSum = 0, maxSum = INT_MIN;

    for (int i = 0; i < n; i++) {
        currentSum += arr[i];
        maxSum = max(maxSum, currentSum);
        currentSum = max(0, currentSum);
    }

    cout << maxSum << endl;

    return 0;
}