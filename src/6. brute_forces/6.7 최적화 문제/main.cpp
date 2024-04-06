#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
double dist[8][8];
vector<double> dists;

double shortestPath(vector<int>& path, vector<bool>& visited, double currentLength) {
    if(path.size() == n) {
        return currentLength;
    }

    double ret = 1415*8;

    for(int next = 0; next < n; next++) {
        if(visited[next]) continue;

        int here = path.back();
        path.push_back(next);
        visited[next] = true;
        dists.push_back(dist[here][next]);

        double cand = shortestPath(path, visited, currentLength + dist[here][next]);

        ret = min(ret, cand);
        visited[next] = false;
        path.pop_back();
        dists.pop_back();
    }

    return ret;
}

int main(void) {
    int c;
    cin >> c;

    cout << fixed;
    cout.precision(10);

    while(c--) {
        cin >> n;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                cin >> dist[i][j];
            }
        }
        
        double ans = 1415*8;

        for(int i = 0; i<n; i++) {
            vector<int> v;
            v.push_back(i);

            vector<bool> visited(n, false);
            visited[i] = true;

            ans = min(ans, shortestPath(v, visited, 0)); 
        }

        cout <<ans << endl;
    }    

    return 0; 
}