#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool pairsum(int arr[], int n, int k) {
    int low = 0, high = n-1;

    while (low < high) {
        if (arr[low] + arr[high] < k)
            low += 1;
        else if (arr[low] + arr[high] > k)
            high -= 1;
        else
            return true;
    }
    return false;
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
    // sorted array required
    for (int i = 0; i < n; i++) 
        cin >> arr[i];
    
    int k; cin >> k;
    cout << pairsum(arr, n, k) << endl;

    return 0;
}