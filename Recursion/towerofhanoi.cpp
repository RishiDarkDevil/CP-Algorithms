#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void towerOfHanoi(int n, char src, char dest, char helper) {
    if (n == 0)
        return;
    towerOfHanoi(n-1, src, helper, dest);
    cout << src << " --> " << dest << endl;
    towerOfHanoi(n-1, helper, dest, src);
}

int main(){

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
    #endif

    int n; cin >> n;

    towerOfHanoi(n, 'A', 'C', 'B');

    return 0;
}