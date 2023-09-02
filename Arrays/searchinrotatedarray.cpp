// https://www.codingninjas.com/studio/problems/search-in-rotated-sorted-array_1082554?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2

#include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

int getPivot(vector<int> &arr) {
    int lb = 0, ub = arr.size() - 1;
    while (lb < ub) {
        int mid = (lb + ub) / 2;
        if (arr[mid] >= arr[0])
            lb = mid + 1;
        else
            ub = mid;
    }
    return ub;
}

int search(vector<int>& arr, int n, int k) {

    int piv_idx = getPivot(arr);
    int lb = 0, ub = arr.size()-1;
    if (k >= arr[piv_idx] && k <= arr[n-1])
        lb = piv_idx;
    else
        ub = piv_idx - 1;
    
    while (lb <= ub) {
        int mid = (lb + ub) / 2;
        if (k >= arr[mid])
            lb = mid + 1;
        else
            ub = mid - 1;
    }
    return (arr[lb - 1] == k)? ub: -1;
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

    cout << search(arr, n, k) << endl;

    return 0;
}