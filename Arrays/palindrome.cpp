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
    char arr[n+1];
    cin >> arr;

    int i = 0;
    while (i < n-1-i) {
        if (arr[i] != arr[n-1-i]) {
            cout << "Not Palindrome" << endl;
            return 0;
        }
        i++;
    }
    cout << "Palindrome" << endl;
    return 0;
}