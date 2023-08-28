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

    int row_start = 0, row_end = m-1, col_start = 0, col_end = n-1, cnt = m*n;

    while ((row_start <= row_end) && (col_start <= col_end)) {

        for (int i = col_start; i <= col_end && cnt > 0; i++) {
            cout << arr[row_start][i] << " "; cnt--;
        }
        row_start++;
        
        for (int i = row_start; i <= row_end && cnt > 0; i++){
            cout << arr[i][col_end] << " "; cnt--;
        }
        col_end--;

        for (int i = col_end; i >= col_start && cnt > 0; i--) {
            cout << arr[row_end][i] << " "; cnt--;
        }
        row_end--;
        
        for (int i = row_end; i >= row_start && cnt > 0; i--) {
            cout << arr[i][col_start] << " "; cnt--;
        }
        col_start++;

        cout << endl;
    }

    return 0;
}