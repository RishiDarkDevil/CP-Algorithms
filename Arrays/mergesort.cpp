#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void merge(int arr[], int l, int mid, int r) {
    int temp[r-l+1];
    int i = l, j = mid+1, k = 0;
    while (i <= mid && j <= r) {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++]; 
    }
    while (j <= r)
        temp[k++] = arr[j++];
    while (i <= mid)
        temp[k++] = arr[i++];

    k = 0;
    for (int i = l; i <= r; i++)
        arr[i] = temp[k++];
}

void mergesort(int arr[], int l, int r) {
    if (l < r) {
        int mid = (l+r) / 2;
        mergesort(arr, l, mid);
        mergesort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }
}

int main(){

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
    #endif

    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) 
        cin >> arr[i];
    
    mergesort(arr, 0, n-1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}