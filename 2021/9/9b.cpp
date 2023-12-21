#include <bits/stdc++.h>

using namespace std;

typedef vector<pair<int, int>> vii;

vii dir {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void debug(const vector<vector<int>>& heightmap) {
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            cout << heightmap[i][j];
        }
        cout << endl;
    } 
        
}

void debug(const vii& lows) {
    for (auto p: lows) {
        cout << "(" << p.first << "," << p.second << ")" << endl;
    }
}

void read(vector<vector<int>>& heightmap) {
    char c;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            cin >> c;
            heightmap[i][j] = c - '0'; 
        }
    }
}

bool outOfBounds(const vector<vector<int>>& heightmap, int i, int j) {
    if (i < 0 || i >= 100 || j < 0 || j >= 100) {
        return true;
    }
    return false;
}

vii findLowPoints(const vector<vector<int>>& heightmap) {
    vii lowPoints;
     
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            bool low = true;
            for (auto d: dir) {
                int rr = i + d.first, cc = j + d.second;
                if (outOfBounds(heightmap, rr, cc)) {
                    continue;
                }
                if (heightmap[i][j] >= heightmap[rr][cc]) {
                    low = false;
                    break;
                }
            }
            if (low) {
                lowPoints.push_back(make_pair(i, j));
            }
        }
    }

    return lowPoints;
}

int bfs(vector<vector<int>>& heightmap, int i, int j) {
    int res = 1;

    queue<pair<int, int>> q;
    heightmap[i][j] = -1;

    q.push(make_pair(i, j));

    while (!q.empty()) {
        pair<int, int> node = q.front();
        q.pop();

        int r = node.first, c = node.second;

        for (auto d: dir) {
            int rr = r + d.first, cc = c + d.second;
            
            if (outOfBounds(heightmap, rr, cc)) continue;

            if (heightmap[rr][cc] != 9 && heightmap[rr][cc] != -1) {
                heightmap[rr][cc] = -1;
                q.push(make_pair(rr, cc));
                res += 1;
            }
        }
    }

    return res;
}

int main() {
    vector<vector<int>> heightmap(100, vector<int>(100));
    read(heightmap);

    vii lowPoints = findLowPoints(heightmap);
    vector<int> basins;

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (find(lowPoints.begin(), lowPoints.end(), make_pair(i, j)) != lowPoints.end()) {
                int res = bfs(heightmap, i, j);
                basins.push_back(res);
            }
        }
    }

    sort(basins.begin(), basins.end());
    
    int len = basins.size();

    int a = basins[len - 1], b = basins[len - 2], c = basins[len - 3];

    cout << "ANS: " << a * b * c << endl;

    return 0;
}