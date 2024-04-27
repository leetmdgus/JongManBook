#include <iostream>

using namespace std;


int cache[1001][1001];

int bino2(int n, int r) {
    if(r == 0 || n == r) return 1;
    if(cache[n][r] != 0) return cache[n][r];

    return cache[n][r] = (bino2(n-1, r-1) + bino2(n-1, r)) % 10'007;
}

int main(void) {
    int n, r;
    cin >> n >> r;

    cout << bino2(n, r) << endl;
    return 0; 
}