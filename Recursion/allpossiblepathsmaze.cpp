#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int allpathscount(int a, int b) {

    if (a == 0 && b == 0)
        return 1;

    int count = 0;
    if (a > 0)
        count += allpathscount(a-1, b);
    if (b > 0)
        count += allpathscount(a, b-1);

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

    cout << allpathscount(n-1, n-1) << endl;

    // ig faster is to simply using combinatorix i.e. in how many ways we can arrange the arrows that gets us from start to finish.

    return 0;
}