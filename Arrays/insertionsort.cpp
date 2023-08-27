#include <bits/stdc++.h>
#include <iostream>
using namespace std;

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

    for (int i = 1; i < n; i++) {
        int j = i, temp = arr[i];
        while ((arr[j-1] > temp) && (j > 0)) {
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = temp;
    }

    for (int i = 0; i < n; i++) 
        cout << arr[i] << " ";

    return 0;
}