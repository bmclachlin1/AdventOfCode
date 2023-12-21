#include <bits/stdc++.h>

using namespace std;

int count_trees(int dx, int dy, const vector<string>& m) {
    int trees = 0;
    int j = 0;

    for (int i = 0; i < m.size(); i += dy) {
        if (m[i][j] == '#') {
            trees++;
        }
        j = (j + dx) % m[i].size();
    }

    return trees;
}

int main() {
    vector<string> map;

    string temp;

    while (getline(cin, temp) && temp != "") {
        map.push_back(temp);
    }

    int dx[] = {1, 3, 5, 7, 1};
    int dy[] = {1, 1, 1, 1, 2};

    long long ans = count_trees(dx[0], dy[0], map);

    for (int i = 1; i < 5; i++) {
        ans *= count_trees(dx[i], dy[i], map);
    }

    cout << ans << endl;

    return 0;
}