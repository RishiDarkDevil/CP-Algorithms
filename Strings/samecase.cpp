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

    string str;
    cin >> str;

    transform(str.begin(), str.end(), str.begin(), ::toupper);

    cout << str << endl;

    transform(str.begin(), str.end(), str.begin(), ::tolower);

    cout << str << endl;

    return 0;
}