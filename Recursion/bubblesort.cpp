#include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

void bubbleSort(vector<int> &arr, int n) {
    if (n == 0)
        return;
    for (int i = 0; i < n-1; i++) {
        if (arr[i] > arr[i+1])
            swap(arr[i], arr[i+1]);
    }
    bubbleSort(arr, n-1);
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
    
    bubbleSort(arr, n);

    for (auto &i: arr) 
        cout << i << " ";
    cout << endl;

    return 0;
}