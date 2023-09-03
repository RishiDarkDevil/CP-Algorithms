#include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

int partition(vector<int> &arr, int lb, int ub) {
    int piv = arr[ub], i = lb - 1;
    for (int j = lb; j < ub; j++) {
        if (arr[j] <= piv) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[ub]);
    return i+1;
}

void quicksort(vector<int> &arr, int lb, int ub) {
    if (lb >= ub)
        return;
    int piv_idx = partition(arr, lb, ub);
    
    quicksort(arr, lb, piv_idx-1);
    quicksort(arr, piv_idx+1, ub);
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
    
    quicksort(arr, 0, n-1);

    for (auto &i: arr) 
        cout << i << " ";
    cout << endl;

    return 0;
}