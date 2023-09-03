// https://leetcode.com/problems/palindromic-substrings/description/?source=submission-ac
#include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

int countPalindromes(string s) {
    int count = 0;
    // counting all the palindromes of odd length
    for (int mid = 0; mid < s.size(); mid++) {
        int k = 0;
        while (mid - k >= 0 && mid + k <= s.size()) {
            if (s[mid - k] == s[mid + k])
                count++;
            else
                break;
            k++;
        }
    }
    // counting all the palindromes of even length
    for (int mid = 0; mid < s.size(); mid++) {
        int k = 1;
        while (mid - k >= 0 && mid + k - 1 <= s.size()) {
            if (s[mid - k] == s[mid + k - 1])
                count++;
            else
                break;
            k++;
        }
    }
    return count;
}

int main(){

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
    #endif

    string s; cin >> s;
    cout << countPalindromes(s) << endl;

    return 0;
}