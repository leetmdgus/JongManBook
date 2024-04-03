#include <iostream>
#include <vector>

using namespace std;

const int n = 5, m = 5;

char board[6][6];

const int dx[8] = {-1, -1, -1, 1, 1, 1, 0, 0};
const int dy[8] = {-1, 0, 1, -1, 0, 1, -1, 1};

bool inRange(int y, int x) {
    if(x < 0 || y < 0 || y >= n || x >= m) return false;
    return true;
}


bool hasWord(int y, int x, const string& word) {
    // 기저사례1 : 시작위치가 범위 밖이라면 무조건 실패
    if(!inRange(y, x)) return false;
    // 기저사례2 : 첫 글자가 일치하지 않으면 실패
    if(board[y][x] != word[0]) return false;
    //기저사례 3: 단어 길이가 1이면 성공
    if(word.size() == 1) return true;

    for(int direction = 0; direction < 8; ++direction) {
        int nextY = y + dy[direction];
        int nextX = x + dx[direction];

        if(hasWord(nextY, nextX, word.substr(1))) {
            return true;
        }
    }

    return false;
}

int main(void) {
    int t;
    cin >> t;

    while(t--) {
        for(int i = 0; i<n ;i++) {
            string str;
            cin >> str;

            for(int j = 0; j<n ;j++) {
                board[i][j] = str[j];
            }
        }

        int k;
        cin >> k;

        vector<string> words(k);
        for(string & a : words) {
            cin >> a;
        }

        for(string str : words) {
            bool flag = false;
            for(int i = 0;i <5; i++) {
                for(int j = 0; j<5; j++) {
                    if(flag) break;
                    
                    flag = hasWord(i, j, str);
                }
            }

            if(flag) {  
                cout << str << " " << "YES\n";
            } else {
                cout << str << " " << "NO\n";
            }
        }
    }

    return 0; 
}