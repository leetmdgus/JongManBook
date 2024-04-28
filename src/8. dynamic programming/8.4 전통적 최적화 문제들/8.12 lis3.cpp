#include <iostream>
#include <string.h>

using namespace std;

int n;
int cache[501], S[500];

int lis3(int start) {
    int & ret = cache[start+1];
    if(ret != -1) return ret;

    ret = 1;

    for(int next = start+1; next< n; next++) {
        if(start == -1 || S[start ] < S[next] ) {
            ret = max(ret, lis3(next)+1);            
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
        for(int i = 0; i<n; i++) {
            cin >> S[i];
        }

        cout << lis3(-1) -1 <<endl;
    }

    return 0; 
}