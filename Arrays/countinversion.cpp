#include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

int merge(vector<int> &arr, int l, int mid, int r) {
    int i = l, j = mid+1, k = 0, count = 0;
    vector<int> temp(r-l+1);
    while (i <= mid && j <= r) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else {
            temp[k++] = arr[j++];
            count += mid-l+1-i;
        }   
    }
    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= r)
        temp[k++] = arr[j++];
    k = 0;
    for (int i = l; i <= r; i++) 
        arr[i] = temp[k++];
    return count;
}

int mergesort(vector<int> &arr, int l, int r) {
    int count = 0;
    if (l < r) {
        int mid = (l+r)/2;
        count += mergesort(arr, l, mid);
        count += mergesort(arr, mid+1, r);

        count += merge(arr, l, mid, r);
    }
    return count;
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

    cout << mergesort(arr, 0, n-1) << endl;

    for (auto &i: arr) 
        cout << i << " ";
    cout << endl;

    return 0;
}