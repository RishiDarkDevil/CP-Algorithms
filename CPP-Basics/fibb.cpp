#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void fibb(int n) {
    int a = 0, b = 1;
    for (int i = 0; i < n; i++) {
        cout << a << " ";
        int sum = a + b;
        a = b;
        b = sum;
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

    fibb(n);

    return 0;
}