#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
vector<int> multiply(const vector<int>&a, const vector<int> &b);
int hugs(const string& members, const string &fans);


void addTo(vector<int>& a, const vector<int>& b, int k) {
    a.resize(max(a.size(), b.size()+k)+1);

    for(int i = 0;i<b.size(); i++) {
        a[i+k] += b[i];
    }

}

void subFrom(vector<int>& a, const vector<int> &b) {
    for(int i = 0; i<b.size(); i++) {
        a[i] -= b[i];
    }
}

vector<int> karatsuba(const vector<int>& a, const vector<int>& b) {
    if(a.size() == 0 || b.size() == 0) return vector<int>();
    if(a.size()<b.size()) return karatsuba(b, a);
    if(a.size() <= 50) return multiply(a, b);

    int half = a.size()/2;
    vector<int> a0(a.begin(), a.begin() + half);
    vector<int> a1(a.begin()+half, a.end());
    vector<int> b0(b.begin(), min(b.end(), b.begin()+half));
    vector<int> b1(min(b.end(), b.begin()+half), b.end());

    vector<int> z2 = karatsuba(a1, b1);
    vector<int> z0 = karatsuba(a0, b0);

    addTo(a1, a0, 0);
    addTo(b1, b0, 0);

    vector<int> z1 = karatsuba(a1, b1);
    subFrom(z1, z0);
    subFrom(z1, z2);

    vector<int> ans;
    addTo(ans, z0, 0);
    addTo(ans, z1, half);
    addTo(ans, z2, half+half);

    return ans;
}


int main(void) {
    int t;
    cin >> t;
    while(t--) {
        string members, fans;
        cin >> members >> fans;
        cout << hugs(members, fans) << endl;
    }
    return 0; 
}

int hugs(const string &members, const string &fans) {
    int N = members.size(), M = fans.size();
    vector<int> A(N), B(M);

    for(int i = 0; i<N; i++) A[i] = (members[i] == 'M');
    for(int i = 0;i <M; i++) B[M-i-1] = (fans[i] == 'M');

    vector<int> C = karatsuba(A, B);
    int allhugs = 0; 
    for(int i = N-1; i<M; i++) {
        if(C[i] == 0) allhugs++;
    }

    return allhugs;
}

vector<int> multiply(const vector<int> &a, const vector<int> &b) {
    vector<int> c(a.size() + b.size() +1, 0);

    for(int i = 0; i<a.size(); i++) {
        for(int j = 0; j<b.size();j ++) {
            c[i+j] += a[i] * b[j];
        }
    }

    return c;
}

