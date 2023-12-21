#include <bits/stdc++.h>

using namespace std;

int main() {
    int curr = -1, prev = -1;

    cin >> curr;

    prev = curr;

    int count = 0;

    while (cin >> curr) {
        if (curr - prev > 0) {
            count++;
        }

        prev = curr;
    }

    cout << count << endl;

    return 0;
}