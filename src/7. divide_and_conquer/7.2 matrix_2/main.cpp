
#include <iostream>
#include <vector>

using namespace std;

class SquareMatrix {
public:
    vector<vector<int>> v;

    SquareMatrix(vector<vector<int>> v) {
        this->v = v;
    }

    int size() const {
        return v.size();
    }

    SquareMatrix operator*(const SquareMatrix& o) {
        int size = o.size();
        
        vector<vector<int>> ans(size, vector<int>(size, 0));

        for(int i = 0; i<size; i++) {
            for(int j = 0; j<size; j++) {
                for(int k = 0; k<size; k++) {
                    ans[i][j] += v[i][k] * o.v[k][j];
                }
            }
        }
        
        return SquareMatrix(ans);
    }

    void printMatrix() {
        for(int i = 0;i <this->size(); i++) {
            for(int j = 0;j <this->size(); j++) {
                cout << (v[i][j])%1'000 << " ";
            }
            cout << endl;
        }
    }
};

SquareMatrix identity(int n) {
    vector<vector<int>> ans(n, vector<int>(n, 0));
    for(int i = 0; i<n ;i++) {
        ans[i][i] = 1;
    }
    return SquareMatrix(ans);
}

SquareMatrix pow(const SquareMatrix& A, long m) {
    if(m == 0) return identity(A.size());
    if(m%2 != 0) return pow(A, m-1)*A;
    SquareMatrix half = pow(A, m/2);
    return half*half;
}

int main(void) {
    int n;
    long b;
    cin >> n >> b;

    vector<vector<int>> v(n, vector<int>(n, 0));
    for(int i = 0; i<n; i++) {
        for(int j = 0;j <n; j++) {
            cin >> v[i][j];
        }
    }

    SquareMatrix matrix(v);
    SquareMatrix ans = pow(matrix, b);
    ans.printMatrix();
    
}