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

int partition(vector<int> &arr, int lb, int ub) {
    int pivot = arr[ub], i = lb - 1;
    for (int j = lb; j < ub; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
            moves += 2;
        }
        comps += 1;
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

void heapify(vector<int>& arr, int lb, int ub) {
    int largest = ub;    
    int left = 2 * ub + 1; 
    int right = 2 * ub + 2;
    comps++;
    if (left < lb && arr[left] > arr[largest])
        largest = left;
    comps++;
    if (right < lb && arr[right] > arr[largest])
        largest = right;
    if (largest != ub) {
        swap(arr[ub], arr[largest]);
        moves += 2;
        heapify(arr, lb, largest);
    }
}

void heapSort(vector<int>& arr, int lb, int ub) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        moves += 2;
        heapify(arr, i, 0);
    }
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

    vector<vector<int>> arrs_ori;
    for (int p = 0; p < 10; p++) {
        for (int k = 0; k < 10; k++) {
            int length = rand() % (ubs[p] - lbs[p] + 1) + lbs[p];
            vector<int> arr;
            for (int i = 0; i < length; i++)
                arr.push_back(rand());
            arrs_ori.push_back(arr);
        }
    }

    moves = 0;
    comps = 0;

    vector<vector<int>> arrs = arrs_ori;

    for (int i = 0; i < 100; i++) {
        quicksort(arrs[i], 0, arrs[i].size()-1);

        if ((i+1) % 10 == 0) {
            cout <<"Average Moves for size range " << (i+1) / 10 << " is: " <<  moves * 1.0 / 10 << endl;
            cout <<"Average Comps for size range " << (i+1) / 10 << " is: " <<  comps * 1.0 / 10 << endl;
            moves = 0;
            comps = 0;
        }
    }

    arrs.clear();

    arrs = arrs_ori;

    // for (int p = 0; p < 10; p++) {
    //     for (int k = 0; k < 10; k++) {
    //         int length = rand() % (ubs[p] - lbs[p] + 1) + lbs[p];
    //         vector<int> arr;
    //         for (int i = 0; i < length; i++)
    //             arr.push_back(rand());
    //         arrs.push_back(arr);
    //     }
    // }

    moves = 0;
    comps = 0;

    cout << "*****************" << endl;

    for (int i = 0; i < 100; i++) {
        mergesort(arrs[i], 0, arrs[i].size()-1);

        if ((i+1) % 10 == 0) {
            cout <<"Average Moves for size range " << (i+1) / 10 << " is: " <<  moves * 1.0 / 10 << endl;
            cout <<"Average Comps for size range " << (i+1) / 10 << " is: " <<  comps * 1.0 / 10 << endl;
            moves = 0;
            comps = 0;
        }
    }

    arrs.clear();
    arrs = arrs_ori;

    // for (int p = 0; p < 10; p++) {
    //     for (int k = 0; k < 10; k++) {
    //         int length = rand() % (ubs[p] - lbs[p] + 1) + lbs[p];
    //         vector<int> arr;
    //         for (int i = 0; i < length; i++)
    //             arr.push_back(rand());
    //         arrs.push_back(arr);
    //     }
    // }

    moves = 0;
    comps = 0;

    cout << "*****************" << endl;

    for (int i = 0; i < 100; i++) {
        heapSort(arrs[i], 0, arrs[i].size()-1);

        if ((i+1) % 10 == 0) {
            cout <<"Average Moves for size range " << (i+1) / 10 << " is: " <<  moves * 1.0 / 10 << endl;
            cout <<"Average Comps for size range " << (i+1) / 10 << " is: " <<  comps * 1.0 / 10 << endl;
            moves = 0;
            comps = 0;
        }
    }
    return 0;
}