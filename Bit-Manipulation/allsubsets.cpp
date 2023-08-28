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
    
    for (int i = 0; i < (1<<n); i++) {
        for (int j = 0; j < n; j++) {
            if (i & (1<<j))
                cout << arr[j] << " ";
        }
        cout << endl;
    }

    return 0;
}