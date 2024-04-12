#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


long N, B;


class SquareMatrix {
   public:
      vector<vector<int>> v;
      SquareMatrix(vector<vector<int>> v) {
         this->v = v;
      }
      int size() const {
         return v.size();
      }
      SquareMatrix operator*(const SquareMatrix o) {
         vector<vector<int>> result(N, vector<int>(N, 0));
         for (int i = 0;i < v.size();i++) {
            for (int j = 0;j < o.v.size();j++) {
               for (int k = 0;k < N;k++) {
                  result[i][j] += v[i][k] * o.v[k][j];
                  result[i][j] %= 1000;
               }
            }
         }
         return result;
      }

};

SquareMatrix identity(int N) {
   vector<vector<int>> v(N,vector<int>(N,0));
   for (int i = 0;i < N;i++) {
      v[i][i] = 1;
   }
   SquareMatrix ans(v);
   return ans;
}

SquareMatrix pow(const SquareMatrix& A, int m) {
   if (m == 0) return identity(A.size());
   if (m % 2 != 0) return pow(A, m - 1) * A;
   SquareMatrix half = pow(A, m / 2);
   return half * half;
}

int main(void) {
   cin >> N >> B;
   vector<vector<int>> first_input(N, vector<int>(N, 0));
   for (int i = 0;i < N;i++) {
      for (int j = 0;j < N;j++) {
         int in;
         cin >> in;
         first_input[i][j] = in;
      }
   }
   SquareMatrix first(first_input);
   
   vector<vector<int>> answer;
   answer = pow(first, B).v;

   for (int i = 0;i < answer.size();i++) {
      for (int j = 0;j < answer.size();j++) {
         cout << answer[i][j] << " ";
      }
      cout << "\n";
   }


   return 0;
}