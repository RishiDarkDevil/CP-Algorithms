#include <bits/stdc++.h>
#include <iostream>
using namespace std;

const int N = 1000000;
int idx[N];

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

    for (int i = 0; i < N; i++) 
        idx[i] = -1;

    int min_rep_idx = -1;
    for (int i = 0; i < n; i++) {
        if (idx[arr[i]] == -1)
            idx[arr[i]] = i;
        else {
            idx[arr[i]] = min(idx[arr[i]], i);
            min_rep_idx = min(idx[arr[i]], min_rep_idx);
        }
    }
    
    cout << min_rep_idx << endl;

    return 0;
}