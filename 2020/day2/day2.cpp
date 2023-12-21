#include <bits/stdc++.h>

using namespace std;

bool valid(string line) {
    istringstream iss(line);

    int lo, hi;
    char c, dummy;
    string password;

    iss >> lo >> dummy >> hi >> c >> dummy >> password;

    int letterCount = 0;
    for (char ch : password) {
        if (c == ch) {
            letterCount++;
        }
    }

    return letterCount >= lo && letterCount <= hi;
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