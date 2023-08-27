#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool isPrime(int n) {
    for (int i = 2; i < sqrt(n); i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main(){

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
    #endif

    int a, b; cin >> a >> b;

    for (int i = a; i <= b; i++) {
        if (isPrime(i))
            cout << i << " ";
    }
        

    return 0;
}