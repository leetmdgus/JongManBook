#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>


using namespace std;

int cache[101][101];
string W, S;

bool matchMemoized(int w, int s) {
    int& ret = cache[w][s];
    if(ret != -1) return ret;

    if(w == W.size()) return ret = (s == S.size());
    
    if(w < W.size() && s < S.size() && (W[w] == '?' || W[w] == S[s]))  {
        return ret = matchMemoized(w+1, s+1);
    }

    if(W[w] == '*') {
        if(matchMemoized(w+1, s) || (s < S.size() && matchMemoized(w, s+1))) {
            return ret = 1;
        }
    }

    return 0; 
}

int main(void) {
    int t;
    cin >> t;

    while(t--) {
        vector<string> v;
        cin >> W;
        int n;
        cin >> n;

        for(int i = 0; i<n; i++) {
            cin >> S;

            memset(cache, -1, sizeof(cache));
            if(matchMemoized(0, 0)) {
                v.push_back(S);
            }
        }

        sort(v.begin(), v.end());
        for(string str : v) {
            cout << str <<endl;
        }
    }
    return 0; 
}