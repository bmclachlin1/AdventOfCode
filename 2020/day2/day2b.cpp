#include <bits/stdc++.h>

using namespace std;

bool valid(string line) {
    istringstream iss(line);

    int lo, hi;
    char c, dummy;
    string password;

    iss >> lo >> dummy >> hi >> c >> dummy >> password;

    int count = 0;
    if (password[lo-1] == c) count++;
    if (password[hi-1] == c) count++;

    return count == 1;
}

int main() {
    string line;
    int count = 0;

    while(getline(cin, line) && line != "") {
        if(valid(line)) {
            count++;
        }
    }

    cout << count << '\n';

    return 0;
}