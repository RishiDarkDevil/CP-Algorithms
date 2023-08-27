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

    long long bin; cin >> bin;

    long long dec = 0, two_pow = 1;
    while (bin > 0) {
        dec += (bin & 1) * two_pow;
        two_pow *= 2;
        bin /= 10;
    }

    cout << dec;

    return 0;
}