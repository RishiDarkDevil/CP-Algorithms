#include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

void sort012(int *arr, int n) {

    int count[4] = {0};
    for (int i = 0; i < n; i++)
        count[arr[i]+1]++;

    for (int i = 1; i < 4; i++) 
        count[i] += count[i-1];

    for (int i = 1; i < 4; i++) {
        for (int j = count[i-1]; j < count[i]; j++)
            arr[j] = i-1;
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
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort012(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}