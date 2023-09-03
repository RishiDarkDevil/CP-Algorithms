#include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

long long reverse_num(long long n) {
    if (n == 0)
        return 0;
    int last_digit = n % 10;
    int num_digits = 0; long long m = n/10;
    while (m > 0) {
        num_digits++;
        m /= 10;
    }
    int p = 1;
    for (int i = 0; i < num_digits; i++) 
        p *= 10;
    return last_digit * p + reverse_num(n/10);
}

bool checkPalindrome(long long N) {
    long long int p = 1;
    long long bin = 0;
    while (N > 0) {
        int rem = N % 2;
        bin += rem * p;
        p *= 10;
        N = N / 2;
    }
	if (bin == reverse_num(bin))
        return true;
    return false;
}

int main(){

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
    #endif

    long long int N; cin >> N;
    cout << checkPalindrome(N) << endl;


    return 0;
}