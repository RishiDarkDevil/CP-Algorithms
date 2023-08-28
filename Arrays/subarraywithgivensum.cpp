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
    
    int S; cin >> S;

    // This method is called the two-pointer method. What was the idea? To maintain as tighter window as possible and increase the window if
    // the cursum is less than what is needed whereas if the cursum is more then we will decrease the window size.
    // This maintains the contiguous nature of the window which is required for the subarray thing to hold.
    int st = 0, en = 0, cursum = arr[0];
    while (en < n) {
        if (cursum < S) {
            en++;
            cursum += arr[en];
        } else if (cursum > S) {
            cursum -= arr[st];
            st++;
        } else {
            cout << st << " " << en << endl;
            return 0;
        }
    }

    cout << -1 << " " << -1 << endl;

    return 0;
}