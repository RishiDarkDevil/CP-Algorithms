#include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

long long int floorSqrt(long long int n) {
    int lb = 0, ub = n;
    // having this condition helps you overcome soooo many confusions in binary search
    while (abs(ub - lb) > 1) {
        long long int mid = lb + (ub - lb) / 2;
        if (mid * mid > n)
            ub = mid - 1;
        else
            lb = mid;
    }
    int l = max(ub, lb);
    if (l*l <= n)
        return l;
    return min(lb, ub);
}


int main(){

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
    #endif

    int n; cin >> n;

    cout << floorSqrt(n) << endl;

    return 0;
}