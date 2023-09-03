#include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

void findComb(string &digits, int idx, string ans, vector<string> &solArr, vector<string> &arr) {
    if (idx == digits.size()) {
        if (ans.compare(""))
            solArr.push_back(ans);
        return;
    }

    string dialpadnums = arr[stoi(digits.substr(idx,1))];
    for (int i = 0; i < dialpadnums.size(); i++) {
        ans.push_back(dialpadnums[i]);
        findComb(digits, idx + 1, ans, solArr, arr);
        ans.pop_back();
    }

}

vector<string> letterCombinations(string digits) {
    vector<string> arr = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> solArr; string ans = "";
    findComb(digits, 0, ans, solArr, arr);
    return solArr;
}

int main(){

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
    #endif

    string digits; cin >> digits;

    vector<string> letter_combos = letterCombinations(digits);
    for (auto &letter_combo: letter_combos)
        cout << letter_combo << endl;

    return 0;
}