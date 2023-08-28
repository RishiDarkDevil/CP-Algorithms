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
    
    const int N = 1e6 + 2;
    int pos_nums[N];
    for (int i = 0; i < N; i++) 
        pos_nums[i] = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0)
            pos_nums[arr[i]] = 1;
    }

    for (int i = 0; i < N; i++) {
        if (!pos_nums[i]) {
            cout << i << endl;
            break;
        }
    }
    

    return 0;
}