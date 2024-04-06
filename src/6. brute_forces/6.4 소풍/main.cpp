#include <iostream>
using namespace std;

int n, m;
bool areFriends[10][10];

int countPairings(bool taken[10]) {
    // 남은 학생들 중 가장 번호가 빠른 학생을 찾는다. 
    int firstFree =-1;

    for(int i = 0; i<n; i++) {
        if(!taken[i]) {
            firstFree = i;
            break;
        }
    }

    if(firstFree == -1) return 1;

    int ret = 0; 
    for(int pairWith = firstFree+1; pairWith < n; pairWith++) {
        if(!taken[pairWith] && areFriends[firstFree][pairWith]) {
            taken[firstFree] = taken[pairWith] = true;
            ret += countPairings(taken);
            taken[firstFree] = taken[pairWith] = false;
        }
    }

    return ret;
}

int main(void) {
    int t;
    cin >> t;

    while(t--) {
        for(int i = 0; i<n; i++) {
            for(int j = 0;j <n; j++) {
                areFriends[i][j] = false;
            }
        }

        cin >> n >> m;
        for(int i = 0; i<m; i++) {
            int a, b;

            cin >> a >> b;

            areFriends[a][b] = true;
            areFriends[b][a] = true;
        }

        bool arr[10] = {false, };
        cout << countPairings(arr) << endl;
    }
    return 0; 
}