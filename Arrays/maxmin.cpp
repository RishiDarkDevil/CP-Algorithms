#include <bits/stdc++.h>
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
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    int maxi = INT_MIN, mini = INT_MAX;
    for (int i = 0; i < n; i++) {
        maxi = max(arr[i], maxi);
        mini = min(arr[i], mini);
    }
    
    cout << "Max: " << maxi << endl;
    cout << "Min: " << mini << endl;

    return 0;
}