// https://www.codingninjas.com/studio/problems/duplicate-in-array_893397?source=youtube&campaign=love_babbar_codestudio1&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio1

#include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

int findDuplicate(vector<int> &arr) {
    int n = arr.size();
    int expectedSum = n*(n+1)/2;
    int actualSum = accumulate(arr.begin(), arr.end(), 0);
    return arr.size() - expectedSum + actualSum;
}

int main(){

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
    #endif

    int n; cin >> n;
    vector<int> arr(n);
    for (auto &i: arr) 
        cin >> i;
    
    cout << findDuplicate(arr) << endl;

    return 0;
}