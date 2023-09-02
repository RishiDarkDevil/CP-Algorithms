#include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

void swapAlternate(vector<int> &arr) {
    for (int i = 0; i < arr.size()-1; i += 2)
        swap(arr[i], arr[i+1]);
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
    
    swapAlternate(arr);

    for (auto &ele: arr) 
        cout << ele << " ";

    return 0;
}