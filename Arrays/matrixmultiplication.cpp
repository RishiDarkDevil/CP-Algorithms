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

    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    int mat1[n1][n2], mat2[n2][n3], mat3[n1][n3];

    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n3; j++)
            mat3[i][j] = 0;
    }

    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++)
            cin >> mat1[i][j];
    }
    for (int i = 0; i < n2; i++) {
        for (int j = 0; j < n3; j++)
            cin >> mat2[i][j];
    }

    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n3; j++) {
            for (int k = 0; k < n2; k++) 
                mat3[i][j] += mat1[i][k] * mat2[k][j];
        }
    }

    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n3; j++)
            cout << mat3[i][j] << " ";
        cout << endl;
    }

    

    return 0;
}