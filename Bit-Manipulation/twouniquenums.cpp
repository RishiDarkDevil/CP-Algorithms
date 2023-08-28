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
    
    int res = 0;
    for (int i = 0; i < n; i++)
        res ^= arr[i];
    
    // finding position of rightmost setbit
    int res1 = res;
    int setbit = 0;
    int pos = 0;
    while (setbit != 1) {
        setbit = res1 & 1;
        pos++;
        res1 >>= 1;
    }

    int res2 = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] & (1 << (pos-1)))
            res2 ^= arr[i];
            
    }

    cout << res2 << endl;
    cout << (res ^ res2) << endl;

    return 0;
}