#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void normalize(vector<int> &num) {
    num.push_back(0);

    for(int i = 0; i+1<num.size(); i++) {
        if(num[i] < 0) {
            int borrow = (abs(num[i]) + 9) / 10;
            num[i+1] -= borrow;
            num[i] += borrow*10;
        } else {
            num[i+1] += num[i]/10;
            num[i] = num[i]%10;
        }
    }

    while(!num.empty() && num.back() == 0) num.pop_back();
}

vector<int> multiply(const vector<int> &a, const vector<int> &b) {
    vector<int> c(a.size()+b.size()+1, 0);
    for(int i = 0; i<a.size(); i++) {
        for(int j = 0; j<b.size(); j++) {
            c[i+j] += a[i] * b[j];
        }
    }

    normalize(c);
    return c;
}


int main(void) {
    int a = 1234;
    int b = 5678;

    vector<int> v1;
    vector<int> v2;

    while(a != 0) {
        v1.push_back(a%10);
        a /= 10;
    }

    while(b!= 0) {
        v2.push_back(b%10);
        b/=10;
    }

    vector<int> v3 = multiply(v1, v2);

    int c =0;
    for(int i = 0;i <v3.size(); i++) {
        c += v3[i] * pow(10, i);
    }

    cout << c<< endl;

    return 0; 
}