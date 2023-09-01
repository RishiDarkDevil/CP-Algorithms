#include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

int take_power(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1)
            res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

int to_decimal(string s) {
    if (s.length() == 1)
        return s[0] - 96;
    return (s[0] - 96) * take_power(20, s.length()-1) +  to_decimal(s.substr(1));
}

int main(){

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
    #endif

    string s; cin >> s;

    cout << to_decimal(s) << endl;

    return 0;
}