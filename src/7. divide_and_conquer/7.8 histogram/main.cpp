#include <iostream>
#include <vector>

using namespace std;

vector<long> h;

int solve(int left, int right) {
    if(left == right) return h[left];
    int mid = (left+ right)/2;

    long ret = max<long>(solve(left, mid), solve(mid+1, right));
    int lo = mid;
    int hi = mid+1;

    long height = min<long>(h[lo], h[hi]);
    ret = max<long>(ret, height*2);

    while(left < lo || right > hi) {
        if(right > hi && (left == lo || h[lo-1] < h[hi+1])) {
            hi++;
            height = min<long>(height, h[hi]);
        } else {
            lo--;
            height = min<long>(height, h[lo]);
        }

        ret = max(ret, height * (hi - lo +1));
    }

    return ret;
}

int main(void) {
    int n;
    cin >> n;

    for(int i = 0; i<n; i++) {
        int x;
        cin >> x;
        h.push_back(x);
    }

    cout << solve(0, n-1) << endl;
    return 0; 
}