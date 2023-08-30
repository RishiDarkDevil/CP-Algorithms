#include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

vector<int> countsort(vector<int> &arr) {

    int maxEle = INT_MIN;
    for (auto &ele: arr)
        maxEle = max(maxEle, ele);

    vector<int> counter(maxEle+1, 0);

    vector<int> sortedArr(arr.size());

    for (auto &i: arr) 
        counter[i]++;
    
    for (int i = 1; i < counter.size(); i++)
        counter[i] += counter[i-1];

    for (int i = arr.size()-1; i >= 0; i--)
        sortedArr[--counter[arr[i]]] = arr[i];
        

    return sortedArr;
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

    vector<int> sortedArr = countsort(arr);

    for (auto &i: sortedArr)
        cout << i << " ";
    cout << endl;

    return 0;
}