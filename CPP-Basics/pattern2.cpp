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

    int row, col;
    cin >> row >> col;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (j == 0 || j == (col-1) || i == 0 || i == (row-1))
                cout << "* ";
            else
                cout << "  ";
        }
        cout << endl;
    }
    

    return 0;
}