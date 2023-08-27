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
    int arr[n+2];
    for (int i = 1; i < n+1; i++) 
        cin >> arr[i];
    
    // padded both sides by -1
    arr[0] = arr[n+1] = -1;

    int num_record_breakers = 0;

    for (int i = 1; i < n+1; i++) {

        if ((arr[i] > arr[i-1]) && (arr[i] > arr[i+1]))
            num_record_breakers++;

        arr[i] = max(arr[i], arr[i-1]);
    }

    cout << num_record_breakers << endl;

    return 0;
}