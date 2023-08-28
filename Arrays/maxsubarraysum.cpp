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
    int arr[n+1];
    arr[0] = 0;
    for (int i = 1; i < n+1; i++) 
        cin >> arr[i];
    
    for (int i = 1; i < n+1; i++)
        arr[i] += arr[i-1];
    
    int maxsum = INT_MIN;
    for (int i = 1; i < n+1; i++) {
        for (int j = i; j < n+1; j++) {
            maxsum = max(arr[j] - arr[i-1], maxsum);
        }
    }

    cout << maxsum << endl;

    return 0;
}