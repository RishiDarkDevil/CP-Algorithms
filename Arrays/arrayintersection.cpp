// https://www.codingninjas.com/studio/problems/intersection-of-2-arrays_1082149?source=youtube&campaign=love_babbar_codestudio1&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio1

#include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m) {

	int pt1 = 0, pt2 = 0;
    vector<int> sol;

    while (pt1 < n && pt2 < m) {

        if (arr1[pt1] > arr2[pt2])
            pt2++;
        else if (arr1[pt1] < arr2[pt2])
            pt1++;
        else {
            sol.push_back(arr1[pt1]);
            pt1++; pt2++;
        }
    }

    return sol;
}

int main(){

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
    #endif

    int n, m; cin >> n >> m;
    vector<int> arr1(n), arr2(m);
    for (auto &i: arr1) 
        cin >> i;
    for (auto &i: arr2) 
        cin >> i;

    vector<int> intersect = findArrayIntersection(arr1, arr1.size(), arr2, arr2.size());
    for (auto &i: intersect) 
        cout << i << " ";

    return 0;
}