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

int findFirstUnique(string s) {

    map<char, pair<int, bool>> uniqueCharPos;

    for (int i = 0; i < s.size(); i++) {
        char ch = s[i];
        if (uniqueCharPos.find(ch) == uniqueCharPos.end())
            uniqueCharPos[ch] = make_pair(i+1, true);
        else
            uniqueCharPos[ch] = make_pair(i+1, false);
    }
    
    int min_pos_unique = INT_MAX;
    for (auto &ele: uniqueCharPos) {
        if (ele.second.second)
            min_pos_unique = min(min_pos_unique, ele.second.first);
    }

    if (min_pos_unique == INT_MAX)
        min_pos_unique = -1;

    return min_pos_unique;
}

int main(){

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
    #endif

    string s; cin >> s;
    cout << findFirstUnique(s) << endl;

    return 0;
}