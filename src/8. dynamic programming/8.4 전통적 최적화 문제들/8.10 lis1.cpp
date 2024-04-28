#include <iostream>
#include <vector>

using namespace std;

int lis(const vector<int> &A) {
    if(A.empty()) return 0; 
    int ret = 0; 
    for(int i = 0; i<A.size(); i++) {
        vector<int> B;
        for(int j = i+1; j<A.size();j ++) {
            if(A[i] < A[j]) {
                B.push_back(A[j]);
            }
        }

        ret = max(ret, 1+lis(B));
    }

    return ret;
}
int main(void) {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> v;
        
        for(int i = 0;i <n; i++) {
            int x;
            cin >> x;
            v.push_back(x);
        }
        
        cout << lis(v) << endl;
    }

    

    return 0; 
}