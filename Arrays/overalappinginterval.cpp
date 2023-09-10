// https://leetcode.com/problems/merge-intervals/submissions/

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

vector<pair<int, int>> findOverlapping (vector<pair<int, int>> &intervals) {

    vector<pair<int, int>> ans;

    sort(intervals.begin(), intervals.end(), 
    [](pair<int, int> int1, pair<int, int> int2) {
        if (int1.first != int2.first) 
            return int1.first <= int2.first;
        else
            return int1.second <= int2.second;    
        });

    int st = intervals[0].first, en = intervals[0].second;
    for (int i = 0; i < intervals.size(); i++) {
        pair<int, int> currInterval = intervals[i];
        if (currInterval.first <= en)
            en = max(en, currInterval.second);
        else {
            ans.push_back(make_pair(st, en));
            st = currInterval.first;
            en = currInterval.second;
        }
        if (i == intervals.size()-1)
            ans.push_back(make_pair(st, en));
    }

    return ans;
}

int main(){

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
    #endif

    int n; cin >> n;
    vector<pair<int, int>> intervals;
    for (int i = 0; i < n; i++) {
        int left, right; cin >> left >> right;
        intervals.push_back(make_pair(left, right));
    }

    vector<pair<int, int>> mergedIntervals = findOverlapping(intervals);
    for (auto &interval: mergedIntervals)
        cout << interval.first << " " << interval.second << endl;

    return 0;
}