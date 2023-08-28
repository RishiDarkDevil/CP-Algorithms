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
    cin.ignore();
    char arr[n+1];

    cin.getline(arr, n+1);
    cin.ignore();

    int maxlength = INT_MIN, wordlength = 0, maxst = 0;
    for (int i = 0; i < n+1; i++) {
        if (arr[i] == ' ' || arr[i] == '\0') {
            maxlength = max(maxlength, wordlength);
            if (maxlength == wordlength)
                maxst = i - maxlength;
            wordlength = 0;
        } else
            wordlength++;
    }

    cout << maxlength << endl;

    for (int i = 0; i < maxlength; i++) 
        cout << arr[i+maxst];

    return 0;
}