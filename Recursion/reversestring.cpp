#include <bits/stdc++.h>
#include <iostream>
using namespace std;

string reverse(string s) {
    if (s.length() == 1)
        return s;
    return reverse(s.substr(1, s.length()-1)) + s[0]; 
}

int main(){

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
    #endif

    string s; cin >> s;

    cout << reverse(s) << endl;

    return 0;
}