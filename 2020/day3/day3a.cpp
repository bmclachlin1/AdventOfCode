#include <bits/stdc++.h>

using namespace std;

int main() {

    vector<string> map;

    string temp;

    while (getline(cin, temp) && temp != "") {
        map.push_back(temp);
    }

    // col #
    int j = 0;
    // num trees
    int trees = 0;

    for (int i = 0; i < map.size(); i++) {
        if (map[i][j] == '#') {
            trees++;
        }
        j = (j + 3) % map[i].size();
    }

    cout << trees << endl;

    return 0;
}