#include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

void powerset(vector<int> &nums, int idx, vector<int> &ans, vector<vector<int>> &all_subsets) {
    if (idx == nums.size()) {
        all_subsets.push_back(ans);
        return;
    }

    ans.push_back(nums[idx]);
    powerset(nums, idx + 1, ans, all_subsets);
    ans.pop_back();
    powerset(nums, idx + 1, ans, all_subsets);
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<int> ans; vector<vector<int>> all_subsets;	
    powerset(nums, 0, ans, all_subsets);
    return all_subsets;
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

    vector<vector<int>> all_subsets = subsets(arr);

    for (auto &subset: all_subsets) {
        for (auto &ele: subset)
            cout << ele << " ";
        cout << endl;
    }

    return 0;
}