#include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

int main(){

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
    #endif

    int n; cin >> n;
    vector<pair<int, int>> arr(n);
    int k = 0;
    for (auto &i: arr) {
        cin >> i.first;
        i.second = k++;
    }
        
    sort(arr.begin(), arr.end(), [](pair<int, int> p1, pair<int, int> p2) {return p1.first < p2.first;});

    vector<int> temp(n);

    for (int i = 0; i < n; i++) 
        temp[arr[i].second] = i;

    for (int i = 0; i < n; i++) 
        cout << temp[i] << " ";
    cout << endl;

    return 0;
}