#include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

void reverse_string(string &s, int lb, int ub) {
    if (lb > ub)
        return;
    swap(s[lb], s[ub]);
    reverse_string(s, lb+1, ub-1);
}

int main(){

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
    #endif

    string s; cin >> s;

    reverse_string(s, 0, s.size()-1);

    cout << s << endl;

    return 0;
}