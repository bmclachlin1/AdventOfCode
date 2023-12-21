#include <bits/stdc++.h>

using namespace std;

void debug(const vector<vector<int>>& heightmap) {
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            cout << heightmap[i][j];
        }
        cout << endl;
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

int main() {
    vector<vector<int>> heightmap(100, vector<int>(100));
    read(heightmap);
    debug(heightmap);

    vector<pair<int, int>> dir {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    vector<int> lows;

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
                lows.push_back(heightmap[i][j]);
            }
        }
    }

    int ans = 0;
    for (int n : lows) {
        ans += n + 1;
    }

    cout << ans << endl;


    return 0;
}