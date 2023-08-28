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

    string s;
    cin >> s;
    int freq[26];

    for (int i = 0; i < 26; i++) 
        freq[i] = 0;

    transform(s.begin(), s.end(), s.begin(), ::toupper);

    for (int i = 0; i < s.length(); i++) {
        freq[s[i] - 'A']++;
    }

    int max_idx = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > freq[max_idx])
            max_idx = i;
    }

    cout << (char)(max_idx + 65) << endl;



    return 0;
}