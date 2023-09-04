#include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

int moves = 0, comps = 0;

void merge(vector<int> &arr, int lb, int mid, int ub) {
    vector<int> temp(ub - lb + 1);
    int i = lb, j = mid + 1, k = 0;
    while (i <= mid && j <= ub) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
        comps++;
        moves++;
    }
    while (i <= mid) {
        temp[k++] = arr[i++];
        moves++;
    }
        
    while (j <= ub) {
        temp[k++] = arr[j++];
        moves++;
    } 
    
    k = lb;
    for (auto &ele: temp) {
        arr[k++] = ele;
        moves++;
    }
}

void mergesort(vector<int> &arr, int lb, int ub) {
    if (ub <= lb)
        return;

    int mid = lb + (ub - lb)/2;
    mergesort(arr, lb, mid);
    mergesort(arr, mid+1, ub);
    merge(arr, lb, mid, ub);
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
        mergesort(arrs[i], 0, arrs[i].size()-1);

        if ((i+1) % 10 == 0) {
            cout <<"Average Moves for size range " << (i+1) / 10 << " is: " <<  moves * 1.0 / 10 << endl;
            cout <<"Average Comps for size range " << (i+1) / 10 << " is: " <<  comps * 1.0 / 10 << endl;
            moves = 0;
            comps = 0;
        }
    }
    return 0;
}