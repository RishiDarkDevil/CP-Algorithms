// https://www.codingninjas.com/studio/problems/first-and-last-position-of-an-element-in-sorted-array_1082549?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2&leftPanelTab=1
// Binary Search to Opitmize over a monotonic function

#include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

int firstBinarySearch(vector<int> &arr, int k) {
    int lb = 0, ub = arr.size()-1;
    while (lb <= ub) {
        int mid = (lb + ub) / 2;
        if (k > arr[mid])
            lb = mid + 1;
        else
            ub = mid - 1;
    }
    return ub + 1;
}

int lastBinarySearch(vector<int> &arr, int k) {
    int lb = 0, ub = arr.size()-1;
    while (lb <= ub) {
        int mid = (lb + ub) / 2;
        if (k >= arr[mid])
            lb = mid + 1;
        else
            ub = mid - 1;
    }
    return lb - 1;
}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k) {
    int first_idx = firstBinarySearch(arr, k), last_idx = lastBinarySearch(arr, k);
    if (first_idx > last_idx)
        return make_pair(-1, -1);
    return make_pair(first_idx, last_idx);
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

    pair<int, int> idxs = firstAndLastPosition(arr, n, k);

    cout << idxs.first << " " << idxs.second << endl;

    return 0;
}