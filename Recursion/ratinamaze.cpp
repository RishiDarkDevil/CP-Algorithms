// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

#include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

bool isSafe(vector<vector<int>> &m, int i, int j, int n) {
    if (i >= 0 && i < n && j >= 0 && j < n && m[i][j] == 1)
        return true;
    return false;
}

void findRoute(vector<vector<int>> &m, int i, int j, int n, string &sol, vector<string> &solPath) {

    if (!isSafe(m, i, j, n))
        return;

    if ((i == n-1) && (j == n-1)) {
        solPath.push_back(sol);

        return;
    }
    if (!(isSafe(m, i+1, j, n) || isSafe(m, i-1, j, n) || isSafe(m, i, j+1, n) || isSafe(m, i, j-1, n)))
        return;
    

    // mark current position
    m[i][j] = 2; 

    // explore all the paths starting from D at this position
    sol.push_back('D');
    findRoute(m, i+1, j, n, sol, solPath);
    sol.pop_back();
    // after vising all that started with D, we need to pop back D from the sol else the paths starting from R will append to D

    // Now visit U and so on.. :)
    sol.push_back('U');
    findRoute(m, i-1, j, n, sol, solPath);
    sol.pop_back();

    sol.push_back('L');
    findRoute(m, i, j-1, n, sol, solPath);
    sol.pop_back();

    sol.push_back('R');
    findRoute(m, i, j+1, n, sol, solPath);
    sol.pop_back();

    m[i][j] = 1; // the current position will become free once we have tried out all the paths in each direction

}

vector<string> findPath(vector<vector<int>> &m, int n) {
    vector<string> solPath; string sol = "";
    findRoute(m, 0, 0, n, sol, solPath);
    sort(solPath.begin(), solPath.end());
    return solPath;
}

int main(){

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
    #endif

    int n; cin >> n;
    vector<vector<int>> M(n, vector<int> (n, 0));
    for (auto &row: M) {
        for (auto &ele: row)
            cin >> ele;
    }

    vector<string> solPath = findPath(M, n);

    for (auto &path: solPath)
        cout << path << endl;

    return 0;
}