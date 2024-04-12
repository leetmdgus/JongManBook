#include <iostream>

using namespace std;

string reverse(string::iterator& it) {
    char head = *(it++);

    if(head == 'b' || head == 'w') {
        return string(1, head);
    }

    string upperLeft = reverse(it);
    string upperRight = reverse(it);
    string lowerLeft = reverse(it);
    string lowerRight = reverse(it);

    return "x" + lowerLeft + lowerRight + upperLeft + upperRight;
}

int main(void) {
    int t;
    cin >> t;
    while(t--) {
        string str;
        cin >> str;

        auto it = str.begin();

        cout << reverse(it) << endl;
    }
    return 0; 
}