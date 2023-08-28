#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void primeSieve(int n) {
    int prime[10000] = {0};

    for (int i = 2; i <= n; i++) {
        if (prime[i] == 0) {
            for (int j = i*i; j <= n; j+=i) {
                prime[j] = 1;
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        if (!prime[i])
            cout << i << " ";
    }
}

int main(){

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
    #endif

    int n; cin >> n;

    primeSieve(n);

    return 0;
}