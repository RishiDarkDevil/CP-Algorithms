#include <iostream>
#include <vector>

using namespace std;

// Counter for moves
long long moves = 0;
long long comps = 0;



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
comps++;

    if (largest != ub) {
               swap(arr[ub], arr[largest]);
        moves += 2;
comps++;

             heapify(arr, lb, largest);
    }
}


void heapSort(vector<int>& arr, int lb, int ub) {
    int n = arr.size();


    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

 
    for (int i = lb - 1; i > 0; i--) {
  
        swap(arr[0], arr[i]);
        moves += 2;
comps++;

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

    int n; cin >> n;
    vector<int> arr(n);
    for (auto &i: arr) 
        cin >> i;

    heapSort(arr, 0, n-1);

    for (auto &i: arr) 
        cout << i << " ";
    cout << endl;

    return 0;
}