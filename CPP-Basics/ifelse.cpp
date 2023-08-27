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

    int a, b, c;
    cin >> a >> b >> c;

    if (a >= b) {
        if (a >= c)
            cout << a;
        else
            cout << c;
    } else {
        if (b >= c)
            cout << b;
        else
            cout << c;
    }

    return 0;
}