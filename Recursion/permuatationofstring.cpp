// the backtracking logic is the recursion tree shouldn't have cross edges.. it should be starting from a root and continue downward with branchings..
// we can't go from one branch and hook up into another branch. This will crash the recursion logic.
// So, a recursion tree will always have the structure where no node will connect another node except via the root.
// Only then the recursion tree is correct! that's why we need backtracking. otherwise you will see the output of first branch will become the input of another branch during next recursion call
// messing up the tree.

#include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

void permutation(vector<int> &arr, int idx, vector<vector<int>> &all_perms) {

    if (idx == arr.size()) {
        all_perms.push_back(arr);
        return;
    }

    for (int i = idx; i < arr.size(); i++) {
        swap(arr[idx], arr[i]);
        permutation(arr, idx+1, all_perms);
        swap(arr[i], arr[idx]);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> all_perms;
    permutation(nums, 0, all_perms);
    return all_perms;
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

    vector<vector<int>> perms = permute(arr);

    for (auto &perm: perms) {
        for (auto &ele: perm)
            cout << ele << " ";
        cout << endl;
    }

    return 0;
}