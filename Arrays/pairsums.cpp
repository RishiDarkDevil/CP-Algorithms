// https://www.codingninjas.com/studio/problems/pair-sum_697295?source=youtube&campaign=love_babbar_codestudio1&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio1

#include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> pairSum(vector<int> &arr, int s){

    vector<vector<int>> solPairs;
    
    sort(arr.begin(), arr.end());
    int st = 0, en = arr.size()-1;
    
    while (st < en) {

        if (arr[st] + arr[en] > s)
            en--;
        else if (arr[st] + arr[en] < s)
            st++;
        else {
            int i = st, j = en;
            for (j = en; (j > st) && (arr[st] + arr[j] == s); j--) {
                for (i = st; (i < j) && (arr[i] + arr[j] == s); i++) {
                    vector<int> pair(2);
                    pair[0] = arr[i];
                    pair[1] = arr[j];
                    solPairs.push_back(pair);
                }
            }
            st = i, en = j;
        }
    }
    sort(solPairs.begin(), solPairs.end(), [](vector<int> a, vector<int> b) {if (a[0] != b[0]) return a[0] < b[0]; else return a[1] < b[1];});
    return solPairs;
}

int main(){

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
    #endif

    int n, k; cin >> n >> k;
    vector<int> arr(n);
    for (auto &i: arr) 
        cin >> i;
    
    vector<vector<int>> solPairs = pairSum(arr, k);

    for (auto &pair: solPairs) {
        for (auto &ele: pair)
            cout << ele << " ";
        cout << endl;
    }

    return 0;
}