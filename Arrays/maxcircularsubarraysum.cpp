#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int kadane(int arr[], int n) {

    int curSum = 0, maxSum = INT_MIN;

    for (int i = 0; i < n; i++) {
        curSum += arr[i];
        maxSum = max(maxSum, curSum);
        curSum = max(0, curSum);
    }

    return maxSum;
}

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
    
    int wrapSum, nonWrapSum, totSum = 0;

    nonWrapSum = kadane(arr, n);

    for (int i = 0; i < n; i++) {
        totSum += arr[i];
        arr[i] = -arr[i];
    }
        
    wrapSum = totSum + kadane(arr, n);

    cout << max(wrapSum, nonWrapSum) << endl;

    return 0;
}