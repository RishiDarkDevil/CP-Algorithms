// https://leetcode.com/problems/peak-index-in-a-mountain-array/
// Why binary search works here? Because here we have a monotonic function slightly non-trivial
// If you do arr[i] > arr[i-1] for all i = 1, ..., n it will be true, true,...., false, false.. we want the end of the true so binary search works :)

#include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

int peakIndexInMountainArray(vector<int>& arr) {
    int lb = 0, ub = arr.size()-1, mid = 0;
    while (lb <= ub) {
        mid = lb + (ub - lb) / 2;
        mid = min(max(1, mid), (int)arr.size()-2);
        if ((arr[mid] > arr[mid-1]) && (arr[mid] > arr[mid+1]))
            return mid;
        else if (arr[mid] > arr[mid+1])
            ub = mid - 1;
        else
            lb = mid + 1;
    }
    return mid;
}

int main(){

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
    #endif

    int n; cin >> n;
    vector<int> arr(n);
    for (auto &i: arr) 
        cin >> i;
    
    cout << peakIndexInMountainArray(arr) << endl;

    return 0;
}