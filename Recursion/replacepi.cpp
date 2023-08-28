#include <bits/stdc++.h>
#include <iostream>
using namespace std;

string replacepi(string s) {

    if (s.length() < 2)
        return s;
    
    if (!(s.substr(0, 2).compare("pi")))
        return "3.14" + replacepi(s.substr(2));
        
    return s.substr(0,1) + replacepi(s.substr(1));
}

int main(){

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
    #endif

    string s; cin >> s;

    cout << replacepi(s);

    return 0;
}