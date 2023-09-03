// https://www.codingninjas.com/studio/problems/ayush-and-ninja-test_1097574?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2&leftPanelTab=0

#include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

int isAllocationPossible(int n, int m, vector<int> &time, long long int min_max) {
    // O(n) check
    long long int currtime = 0;
    int i = 0, k = 0;
    for (i = 0; i < m && currtime <= min_max; i++) {
        currtime += time[i];
        if (currtime > min_max) {
            currtime = time[i]; k++;
        }
    }
    if (i < m || currtime > min_max) // if the loop ended before reaching end means currtime > min_max somewhere i.e. there exists an element > min_max also make sure if the entire array is traversed and then we get currtime  > max_min i.e. the last segment exceeds max_min so return false!
        return false;
    if (k+1 > n) // if the number of days required is greater than what is maximum allowed
        return false;
    return true; // otherwise the allocation is a plausible one
}

long long ayushGivesNinjatest(int n, int m, vector<int> time) {	
	long long int lb = 0, ub = accumulate(time.begin(), time.end(), 0);
    while (abs(ub - lb) > 1) {
        long long mid = lb + (ub - lb) / 2;
        if (isAllocationPossible(n, m, time, mid))
            ub = mid;
        else
            lb = mid + 1;
    }
    if (isAllocationPossible(n, m, time, min(ub, lb)))
        return min(ub, lb);
    return max(ub, lb);
}

int main(){

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
    #endif

    int N, M; cin >> N >> M;
    vector<int> arr(M);
    for (auto &i: arr) 
        cin >> i;

    cout << ayushGivesNinjatest(N, M, arr) << endl;

    return 0;
}