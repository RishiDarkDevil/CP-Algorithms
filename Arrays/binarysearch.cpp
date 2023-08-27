#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int k) {
    // arr should be in ascending order. This function performs binary search.
    int lb = 0, ub = n-1;
    while (ub >= lb) {
        int mid = (lb + ub) / 2;
        if (k > arr[mid])
            lb = mid + 1;
        else if (k < arr[mid])
            ub = mid - 1;
        else
            return mid;
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
    
    cout << binarySearch(arr, n, k) << endl;
    
    return 0;
}