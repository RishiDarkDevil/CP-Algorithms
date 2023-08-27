#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int k) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == k)
            return i;
    }
    return -1;
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

    int k; cin >> k;

    cout << linearSearch(arr, n, k) << endl;

    return 0;
}