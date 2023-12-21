#include <bits/stdc++.h>

using namespace std;

int main() {
    string direction;

    int horizontal = 0;
    int depth = 0;
    int dist = 0;

    while (cin >> direction) {
        cin >> dist;

        if (direction == "forward") {
            horizontal += dist;
        } else if (direction == "up") {
            depth -= dist;
        } else {
            depth += dist;
        }
    }

    cout << depth << " * " << horizontal << " = " << depth * horizontal << endl;

    return 0;
}