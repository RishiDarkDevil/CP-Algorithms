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

    // taking in the decimal number
    int dec; cin >> dec;

    long long bin = 0, p = 1;
    while(dec > 0) {
        bin += (dec & 1) * p;
        dec /= 2;
        p *= 10;
    }

    cout << bin << endl;

    return 0;
}