#include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

int diff(string s1, string s2) {
    
    int count = 0;
    for (int i = 0; i < s1.length(); i++)
        count += (s1[i] = s2[i]);
    
    return count;
}

int main(){

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
    #endif

    string s1, s2; cin >> s1 >> s2;

    cout << diff(s1, s2) << endl;

    return 0;
}