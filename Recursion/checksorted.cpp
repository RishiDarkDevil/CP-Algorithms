#include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

bool isSorted(vector<int> &arr, int n) {
    if (n == 0)
        return true;
    return (arr[n] >= arr[n-1]) && isSorted(arr, n-1);
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
    
    cout << isSorted(arr, n-1) << endl;

    return 0;
}