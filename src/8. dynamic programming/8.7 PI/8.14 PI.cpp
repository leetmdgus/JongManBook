#include <iostream>
#include <limits>
#include <string.h>


using namespace std;

const int INF = 98654321;
string N;
int cache[10002];

int classify(int a, int b) {
    string M = N.substr(a, b);

    // 모든 숫자가 같을 때 난이도 : 1
    if(M == string(M.size(), M[0])) return 1;

    // 공차가 1이거나 -1인 등차수열일때
    bool flag = true;
    int d = M[1] - M[0];
    for(int i = 2; i<M.size(); i++) {
        if(M[i] - M[i-1] != d) {
            flag = false;
        }
    }

    if(flag && (d == -1 || d == 1)) return 2;

    // 숫자가 등차수열을 이룰 때
    if(flag) return 5;

    // 두 개의 숫자가 번갈아가며 출현할 때
    flag = true;
    for(int i = 0; i<M.size(); i++) {
        if(M[i%2] != M[i])  {
            flag = false;
        }
    } 
    
    if(flag) return 4;

    // 그 외
    return 10; 
}

int memoized(int start) {
    if(start == N.size()) return 0; 

    int& ret = cache[start];

    if(ret != -1) return ret;
    ret = INF;

    for(int L = 3; L<=5; L++) {
        if(start + L <= N.size()) {
            ret = min(ret, memoized(start+L) + classify(start, L));
        }
    }

    return ret;
}

int main(void) {
    int c;
    cin >> c;

    while(c--) {
        cin >> N;
        memset(cache, -1, sizeof(cache));
        cout << memoized(0) <<endl;
    }
}