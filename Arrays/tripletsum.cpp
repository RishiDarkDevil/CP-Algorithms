// https://www.codingninjas.com/studio/problems/triplets-with-given-sum_893028?source=youtube&campaign=LoveBabbar_Codestudiovideo1&utm_source=youtube&utm_medium=affiliate&utm_campaign=LoveBabbar_Codestudiovideo1&leftPanelTab=0
// Here optimization was possible unlike the `pairsums.cpp` because here they want distinct triplets

#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {

    set<vector<int>> solTrips;
	vector<vector<int>> solTriplets;
    if (n < 3)
        return solTriplets;
    
    sort(arr.begin(), arr.end());
    
    for (int i = 0; i < n; i++) {
        int target = K - arr[i], j = i+1, k = arr.size()-1;
        while (j < k) {
            if ((arr[j] + arr[k]) < target)
                j++;
            else if ((arr[j] + arr[k]) > target)
                k--;
            else {
                vector<int> trip(3);
                trip[0] = arr[i];
                trip[1] = arr[j];
                trip[2] = arr[k];
                solTrips.insert(trip);
                j++; k--;
            }
        }
    }

    for (auto &trip: solTrips)
        solTriplets.push_back(trip);
    
    return solTriplets;
}

int main(){

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
    #endif

    int n, K; cin >> n;
    vector<int> arr(n);
    for (auto &i: arr) 
        cin >> i;
    cin >> K;

    vector<vector<int>> solTriplets = findTriplets(arr, n, K);

    for (auto &triplet: solTriplets) {
        for (auto &&ele: triplet)
            cout << ele << " ";
        cout << endl;
    }

    return 0;
}