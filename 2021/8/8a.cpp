#include <bits/stdc++.h>

using namespace std;

void debug(const vector<vector<string>>& lines) {
    for (int i = 0; i < lines.size(); i++) {
        for (int j = 0; j < lines[i].size(); j++) {
            cout << lines[i][j] << " ";
        }
        cout << endl;
    }
}

void read(vector<vector<string>>& lines) {
    string line = "";
    int i = 0;

    while (getline(cin, line) && line != "") {
        stringstream ss(line);

        for (int k = 0; k < 15; k++) {
            if (k == 10) {
               char ignoreChar; 
               ss >> ignoreChar;
            } else {
                string segment;
                ss >> segment;
                lines[i].push_back(segment);
            }
        }

        i++;
    }
}

int main() {
    vector<vector<string>> lines(200);
    read(lines);
    debug(lines);

    int ans = 0;
    for (const auto& line: lines) {
        for (int i = 10; i < 14; i++) {
            int len = line[i].length();
            if (len == 2 || len == 3 || len == 4 || len == 7) {
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}