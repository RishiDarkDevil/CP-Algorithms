#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void subseq(string s, string ans) {

    if (!s.length()) {
        cout << ans << endl;
        return;
    }
    subseq(s.substr(1), ans);
    subseq(s.substr(1), ans + s[0]);
}

int main(){

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
    #endif

    string s; cin >> s;

    subseq(s, "");

    return 0;
}