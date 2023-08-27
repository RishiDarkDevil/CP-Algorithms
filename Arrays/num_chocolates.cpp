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

    int money; cin >> money;

    int num_chocs = money, num_wraps = money;

    while (num_wraps > 2) {
        num_chocs += num_wraps / 3;
        num_wraps = (num_wraps % 3) + (num_wraps / 3);
    }

    cout << num_chocs;

    return 0;
}