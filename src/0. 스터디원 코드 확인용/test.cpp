#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string reverse(string::iterator& it) {
   char head = *it;
   it++;
   if (head == 'b' || head == 'w') return string(1, head);
   string upperLeft = reverse(it);
   string upperRight = reverse(it);
   string lowerLeft = reverse(it);
   string lowerRight = reverse(it);

   return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}

int T;

int main(void) {
   cin >> T;
   for (int i = 0;i < T;i++) {
      string str;
      cin >> str;
      auto it = str.begin();
      cout << reverse(it) << endl;
   }
   return 0;
}