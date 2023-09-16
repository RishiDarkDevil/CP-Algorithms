#include <bits/stdc++.h>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <iostream>
using namespace std;

char lostCharNW (string sent, string rec) {
    int st1 = 0, st2 = 0;

    while (st1 < sent.size() && st2 < rec.size()) {
        if (sent[st1] == rec[st2]) {
            st1++; st2++;
        }
        else
            return sent[st1];
    }

    return sent[sent.size()-1];
}

int main(){

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
    #endif

    string s1, s2; cin >> s1 >> s2;

    cout << lostCharNW(s1, s2);

    return 0;
}