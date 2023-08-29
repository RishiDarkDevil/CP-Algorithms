#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void perm(string s, string ans) {

    if (s.empty()) {
        cout << ans << endl;
        return;
    }

    for (int i = 0; i < s.length(); i++)
        perm(s.substr(0,i) + s.substr(i+1), ans + s[i]);
}

int main(){

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
    #endif

    string s; cin >> s;

    perm(s, "");
    
    return 0;
}