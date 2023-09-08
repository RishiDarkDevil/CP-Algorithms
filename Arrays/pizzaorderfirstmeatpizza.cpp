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

vector<int> first_meat_pizza(vector<int> &orderPlaced, int window_size) {

    vector<int> answer;
    
    queue<pair<int, int>> meat_pizzas;

    for (int i = 0; i < orderPlaced.size(); i++) {

        int order = orderPlaced[i];

        if (order < 0)
            meat_pizzas.push(make_pair(order, i));
        
        if (i < window_size-1)
            continue;

        if (i - meat_pizzas.front().second >= window_size)
            meat_pizzas.pop();

        if (!meat_pizzas.empty())
            answer.push_back(meat_pizzas.front().first);
        else
            answer.push_back(0);
    }

    return answer;
}

int main(){

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
    #endif

    int n; cin >> n;
    vector<int> arr(n);
    for (auto &i: arr) 
        cin >> i;

    int k; cin >> k;

    vector<int> answer = first_meat_pizza(arr, k);

    for (auto &i: answer)
        cout << i << " ";
    cout << endl;

    return 0;
}