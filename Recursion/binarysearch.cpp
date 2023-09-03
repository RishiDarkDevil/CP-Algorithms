#include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

int binarySearch(vector<int> arr, int lb, int ub, int k) {
    if (ub < lb)
        return -1;
    int mid = lb + (ub - lb) / 2;
    if (arr[mid] == k)
        return mid;
    else if (arr[mid] < k)
        return binarySearch(arr, mid + 1, ub, k);
    else
        return binarySearch(arr, lb, mid - 1, k);
}

int main(){

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
    #endif

    int n, k; cin >> n >> k;
    vector<int> arr(n);
    for (auto &i: arr) 
        cin >> i;

    cout << binarySearch(arr, 0, arr.size()-1, k) << endl;

    return 0;
}