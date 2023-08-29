#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int numpairs(int n) {

    if (n == 0 || n == 1 | n == 2)
        return n;

    return numpairs(n-1) + (n-1) * numpairs(n-2);
}

int main(){

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
    #endif

    int n; cin >> n;

    cout << numpairs(n);

    return 0;
}