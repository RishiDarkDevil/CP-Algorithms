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

    int m, n;
    cin >> m >> n;
    int arr[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    }

    int k; cin >> k;

    int row_idx = 0, col_idx = n-1;

    while (row_idx >= 0 && row_idx < m && col_idx >= 0 && col_idx < n) {
        if (k > arr[row_idx][col_idx])
            row_idx++;
        else if (k < arr[row_idx][col_idx])
            col_idx--;
        else {
            cout << row_idx << " " << col_idx << endl;
            return 0;
        }
    }

    cout << "Not Found" << endl;

    return 0;
}