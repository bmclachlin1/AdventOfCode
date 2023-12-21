#include <bits/stdc++.h>

using namespace std;

int main() {
    int horizontal = 0;
    int depth = 0;
    int aim = 0;

    string direction;
    int dist;

    while (cin >> direction) {
        cin >> dist;

        if (direction == "forward") {
            horizontal += dist;
            depth += aim * dist;
        } else if (direction == "up") {
            aim -= dist;
        } else {
            aim += dist;
        }
    }

    cout << horizontal * depth << endl;

    return 0;
}