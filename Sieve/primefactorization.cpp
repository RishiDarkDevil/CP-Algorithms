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

    int n; cin >> n;

    int spf[100000];
    for (int i = 0; i <= n; i++)
        spf[i] = 0; 

    for (int i = 2; i <= n; i++) {
        if (!spf[i]) {
            spf[i] = i;
            for (int j = i*i; j <= n; j += i) {
                if (!spf[j])
                    spf[j] = i;
            }
        }
    }

    while (n != 1) {
        cout << spf[n] << " ";
        n /= spf[n];
    }

    return 0;
}