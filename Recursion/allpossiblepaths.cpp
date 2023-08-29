#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int allpathscount(int n) {

    if (!n)
        return 1;

    int count = 0;
    for (int i = 1; i < 7 && i <= n; i++) 
        count += allpathscount(n-i);

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

    cout << allpathscount(n) << endl;

    return 0;
}