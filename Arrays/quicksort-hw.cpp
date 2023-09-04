#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <time.h>
using namespace std;

int moves = 0, comps = 0;

int partition(vector<int> &arr, int lb, int ub) {
    int pivot = arr[ub], i = lb - 1;
    for (int j = lb; j < ub; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
            moves += 2;
            comps += 1;
        }
    }
    swap(arr[i+1], arr[ub]);
    moves += 2;
    return i+1;
}

void quicksort(vector<int> &arr, int lb, int ub) {
    if (ub <= lb)
        return;
    int piv_idx = partition(arr, lb, ub);
    quicksort(arr, lb, piv_idx-1);
    quicksort(arr, piv_idx+1, ub);
}

int main(){

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
    #endif

    srand(time(NULL));
    
    vector<int> lbs = {10, 101, 301, 701, 1201, 2001, 3001, 4501, 6001, 8001};
    vector<int> ubs = {100, 300, 700, 1200, 2000, 3000, 4500, 6000, 8000, 10000};

    vector<vector<int>> arrs;
    for (int p = 0; p < 10; p++) {
        for (int k = 0; k < 10; k++) {
            int length = rand() % (ubs[p] - lbs[p] + 1) + lbs[p];
            vector<int> arr;
            for (int i = 0; i < length; i++)
                arr.push_back(rand());
            arrs.push_back(arr);
        }
    }

    for (int i = 0; i < 100; i++) {
        quicksort(arrs[i], 0, arrs[i].size()-1);

        if ((i+1) % 10 == 0) {
            cout <<"Average Moves for size range " << (i+1) / 10 << " is: " <<  moves * 1.0 / 10 << endl;
            cout <<"Average Comps for size range " << (i+1) / 10 << " is: " <<  comps * 1.0 / 10 << endl;
            moves = 0;
            comps = 0;
        }
    }
    return 0;
}