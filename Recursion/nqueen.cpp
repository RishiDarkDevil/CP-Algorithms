#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool isSafe(int** arr, int x, int y, int n) {
    if (x < 0 || x >= n || y < 0 || y >= n)
        return false;
    
    int k = 1;
    for (int i = x-1; i >= 0; i--) {
        if (arr[i][y])
            return false;
        if ((y+k < n) && arr[i][y+k])
            return false;
        if ((y-k >= 0) && arr[i][y-k])
            return false;
        k++;
    }
    return true;
}

bool placequeens(int **arr, int x, int numQueens, int n) {
    /*
    The interpretation of what this function is placequeens returns true if it is possible to place
    `numQueens` number of queens from `xth` row onwards on the arr board o.w. false.
    */

    if (numQueens == 0)
        return true;

    for (int y = 0; y < n; y++) {
        if (isSafe(arr, x, y, n)) {
            arr[x][y] = 1;
            if (placequeens(arr, x+1, numQueens-1, n))
                return true;
            arr[x][y] = 0;
        }
    }

    return false;
}

int main(){

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
    #endif

    int n, numqueens; cin >> n >> numqueens;
    int **arr = new int*[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++)
            arr[i][j] = 0;
    }
        
    if (placequeens(arr, 0, numqueens, n)) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << arr[i][j] << " ";
            cout << endl;
        }
    }

    return 0;
}