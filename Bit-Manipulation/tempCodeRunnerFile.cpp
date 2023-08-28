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

    int bitfreq[64];

    for (int i = 0; i < 64; i++) 
        bitfreq[i] = 0;
    
    for (int i = 0; i < 64; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[j] & (1 << i)){
                bitfreq[i]++;}
        }
    }

    cout << (1 << 0) << endl;

    for (int i = 0; i < n; i++)
        cout << bitfreq[i] << " ";
    cout << endl;

    int res = 0;
    for (int i = 0; i < 64; i++)
        res |= (int)(bitfreq[i] % 3 == 0 && bitfreq[i] > 0) << i;

    cout << res << endl;

    return 0;
}