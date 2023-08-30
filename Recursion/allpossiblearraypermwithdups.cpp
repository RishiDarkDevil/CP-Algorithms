#include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> ans;

void permute(vector<int> a, int idx) {

    if (idx == a.size()) {
        ans.push_back(a);
        return;
    }

    for (int i = idx; i < a.size(); i++) {
        if (i != idx && a[i] == a[idx])
            continue;
        swap(a[idx], a[i]);
        permute(a, idx+1);
    }
    return;
}

int main(){

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
    #endif

    int n; cin >> n;
    vector<int> a(n);
    for (auto &i: a)
        cin >> i;
    
    sort(a.begin(), a.end());

    permute(a, 0);

    for (auto &row: ans) {
        for (auto &ele: row)
            cout << ele << " ";
        cout << endl;
    }

    return 0;
}