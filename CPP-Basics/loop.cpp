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

    int n;
    cin >> n;

    int sum = 0;
    for (int i = 0; i < n+1; i++) {
        sum += i;
    }

    cout << sum;
    

    return 0;
}