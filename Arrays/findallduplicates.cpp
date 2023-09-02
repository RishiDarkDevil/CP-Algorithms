// https://leetcode.com/problems/find-all-duplicates-in-an-array/submissions/
// The idea here was to use the fact that the integers lie within [1,n] to modify the original array itself.
// How this method striked? because the elements can be at max the size of the array. I might think of using the same array as a marker
// And I do not need the exact count. twice or once could be encoded using -ve and +ve respectively.
// Very interesting approach.

#include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

vector<int> findDuplicates(vector<int>& nums) {

    vector<int> dups;
    
    for (auto &ele: nums) {
        if (nums[abs(ele) - 1] < 0) {
            dups.push_back(abs(ele));
            continue;
        }
        nums[abs(ele) - 1] = -1 * nums[abs(ele) - 1];
    }

    return dups;    
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

    vector<int> dups = findDuplicates(arr);

    for (auto &i: dups)
        cout << i << " ";

    return 0;
}