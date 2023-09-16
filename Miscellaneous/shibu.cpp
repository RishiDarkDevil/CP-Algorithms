#include <bits/stdc++.h>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <iostream>
using namespace std;

int main() {
    int n, K;

    int n; cin >> n;
    vector<int> arr(n);
    for (auto &i: arr) 
        cin >> i;

    cin >> K;

    // Initialize a count variable to keep track of elements less than K
    int count = 0;

    // Iterate through the list and count elements less than K
    for (int i = 0; i < n; i++) {
        if (arr[i] < K) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}