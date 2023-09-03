#include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

void helper(string str, string ans, int idx, vector<string> &all_subseqs){
	if (idx == str.size()) {
        if (ans.compare(""))
            all_subseqs.push_back(ans);
        return;
    }

    // exclude
    helper(str, ans, idx+1, all_subseqs);

    // include
    ans += str[idx];
    helper(str, ans, idx+1, all_subseqs);
}

vector<string> subsequences(string str){
	
	vector<string> all_subseqs; string ans = "";
    helper(str, ans, 0, all_subseqs);
	
    return all_subseqs;
}

int main(){

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
    #endif

    string s; cin >> s;
    vector<string> subseqs = subsequences(s);

    for (auto &subseq: subseqs)
        cout << subseq << endl;

    return 0;
}