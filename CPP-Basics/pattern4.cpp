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

    int row; cin >> row;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < (row-i-1); j++)
            cout << "  ";
        for (int j = 0; j <= i; j++)
            cout << "* ";
        cout << endl;
    }

    return 0;
}