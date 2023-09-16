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

vector<int> funcDistance(vector<int> inputDist, int start, int end) {

    vector<int> answer;

    for (auto &dist: inputDist) {
        if (dist >= start && dist <= end)
            answer.push_back(dist);
    }

    return answer;
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
    
    int lb, ub; cin >> lb >> ub;

    vector<int> answer = funcDistance(arr, lb, ub);

    for (auto &ele: answer)
        cout << ele << " ";
    cout << endl;

    return 0;
}