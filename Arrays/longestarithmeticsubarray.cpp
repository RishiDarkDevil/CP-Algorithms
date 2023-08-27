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
    
    for (int i = 0; i < n-1; i++)
        arr[i] = arr[i+1] - arr[i];

    int curr_length = 1, pd = arr[0], max_length = INT_MIN;
    for (int i = 1; i < n-1; i++) {
        if (arr[i] == pd) {
            curr_length++;
        } else {
            curr_length = 1;
            pd = arr[i];
        }
        max_length = max(max_length, curr_length);
    }

    cout << max_length + 1 << endl;

    return 0;
}