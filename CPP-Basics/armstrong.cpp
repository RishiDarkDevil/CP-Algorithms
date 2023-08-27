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
    int m = n;
    int sum = 0;
    while (n > 0) {
        sum += pow(n%10, 3);
        n /= 10;
    }

    if (sum == m)
        cout << "Armstrong" << endl;
    else
        cout << "Not Armstrong" << endl;
    

    return 0;
}