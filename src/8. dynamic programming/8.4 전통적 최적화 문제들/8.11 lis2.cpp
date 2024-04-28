#include <iostream>
#include <string.h>

using namespace std;

int n;
int cache[500], S[500];

int lis2(int start) {
    int& ret = cache[start];

    if(ret != -1) return ret;

    ret = 1;
    for(int next = start+1; next < n; ++next) {
        if(S[start] < S[next]) {
            ret = max<int>(ret, lis2(next)+1);
        }
    }

    return ret;
}

int main(void) {
    int t;
    cin >> t;

    while(t--) {
        cin >> n;

        memset(cache, -1, sizeof(cache));

        for(int i = 0; i < n;i ++) {
            cin >> S[i];
        }

        int maxV = 0; 
        for(int i= 0; i<n; i++) {
            maxV = max<int>(maxV, lis2(i));
        }
        cout << maxV << endl;
    }   
    return 0; 
}