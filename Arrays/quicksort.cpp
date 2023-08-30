#include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

int partition(vector<int> &arr, int l, int r) {
    int piv = arr[r];
    int i = l-1; // just keep in mind here that i point to a value which is < piv always
    for (int j = l; j <= r-1; j++) {
        if (arr[j] < piv) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[r]);
    return i+1;
}

void quicksort(vector<int> &arr, int l, int r) {
    if (l < r) {
        int pi = partition(arr, l, r);

        quicksort(arr, l, pi-1);
        quicksort(arr, pi+1, r);
    }
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