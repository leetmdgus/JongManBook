#include <iostream>
#include <string.h>

using namespace std;

int n;
int board[100][100];
int cache[100][100];

int jump2(int y, int x) {
    if(x>=n || y >=n) return 0; 
    if(x == n-1 && y == n-1) return 1;

    int& ret = cache[y][x];
    if(ret != -1) return ret;

    int jumpSize = board[y][x];

    return ret = (jump2(y+jumpSize, x) || jump2(y, x+jumpSize));
}

int main(void) {
    int t;
    cin >> t;

    while(t--) {
        cin >> n;
        
        memset(cache, -1, sizeof(cache));

        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                cin >> board[i][j];
            }
        }

        if(jump2(0, 0)){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}