#include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

int sumOfElements(vector<int> &arr, int st) {

    if (st == arr.size())
        return 0;
        
    return arr[st] + sumOfElements(arr, st+1);
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

    cout << sumOfElements(arr, 0) << endl;

    return 0;
}