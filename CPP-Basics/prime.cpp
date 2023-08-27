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

    int n;
    cin >> n;

    for (int i = 2; i < n; i++) {
        if (!(n % i)) {
            cout << "Non Prime" << endl;
            return 0;
        }
    }
    cout << "Prime";

    return 0;
}