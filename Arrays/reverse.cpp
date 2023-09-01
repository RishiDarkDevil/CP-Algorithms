#include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

void reverse(vector<int> &arr) {
    int st = 0, en = arr.size()-1;

    while (st < en) {
        swap(arr[st], arr[en]);
        st++; en--;
    }
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

    reverse(arr);

    for (auto &ele: arr)
        cout << ele << " ";
    cout << endl;

    return 0;
}