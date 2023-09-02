// https://leetcode.com/problems/unique-number-of-occurrences/

#include <bits/stdc++.h>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;

bool uniqueOccurrences(vector<int> &arr) {
    
    unordered_map<int, int> countMap;
    unordered_set<int> count;

    // average time complexity is O(N)
    for (auto &ele: arr) {
        // average time complexity is O(1)
        if (countMap.find(ele) == countMap.end())
            countMap[ele] = 1;
        countMap[ele]++;
    }

    for (auto &item: countMap)
        count.insert(item.second);

    return countMap.size() == count.size();
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
    
    cout << uniqueOccurrences(arr) << endl;

    return 0;
}