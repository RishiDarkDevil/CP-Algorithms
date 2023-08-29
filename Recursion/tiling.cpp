#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int numtiles(int n) {

    if (n==1 | n == 0)
        return n;

    int count = 0;
    count += numtiles(n-1) + numtiles(n-2);

    return count;
}

int main(){

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
    #endif

    int n; cin >> n;

    cout << numtiles(n) << endl;

    return 0;
}