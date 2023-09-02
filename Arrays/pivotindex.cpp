// https://leetcode.com/problems/find-pivot-index/description/

#include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

int pivotIndex(vector<int>& nums) {

    int totSum = accumulate(nums.begin(), nums.end(), 0);

    int leftSum = 0, rightSum = totSum;
    for (int i = 0; i < nums.size(); i++) {
        rightSum -= nums[i];
        if (leftSum == rightSum)
            return i;
        leftSum += nums[i];
    }
    return -1;
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
    
    cout << pivotIndex(arr) << endl;

    return 0;
}