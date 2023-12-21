#include <bits/stdc++.h>

using namespace std;

struct Point {
    int x, y;

    Point(int xCoord, int yCoord) : x(xCoord), y(yCoord) {}
};

struct LineSegment {
    Point p1, p2;

    LineSegment(Point a, Point b) : p1(a), p2(b) {}
};

int main() {
    string s;
    vector<LineSegment> lines;

    int frequencies[1000][1000];

    for (int i = 0; i < 1000; i++)
        for (int j = 0; j < 1000; j++)
            frequencies[i][j] = 0;

    while (getline(cin, s) && s != "") {
        stringstream ss(s);
        int x1, y1, x2, y2;
        char dummy;
        ss >> x1 >> dummy >> y1 >> dummy >> dummy >> x2 >> dummy >> y2;
        
        if (x1 == x2 || y1 == y2) {
            Point p1 = Point(x1, y1);
            Point p2 = Point(x2, y2);
            LineSegment l = LineSegment(p1, p2);
            lines.push_back(l);
        }
    }

    for (LineSegment ls : lines) {
        int x1, y1, x2, y2;
        x1 = ls.p1.x;
        y1 = ls.p1.y;
        x2 = ls.p2.x;
        y2 = ls.p2.y;

        if (x1 == x2) {
            int row = x1;
            if (y1 < y2) {
                for (int j = y1; j <= y2; j++) {
                    frequencies[row][j]++;
                }
            } else if (y2 < y1) {
                for (int j = y2; j <= y1; j++) {
                    frequencies[row][j]++;
                }
            }
        } else if (y1 == y2) {
            int col = y1;
            if (x1 < x2) {
                for (int i = x1; i <= x2; i++) {
                    frequencies[i][col]++;
                }
            } else if (x2 < x1) {
                for (int i = x2; i <= x1; i++) {
                    frequencies[i][col]++;
                }
            }
        }
    }

    int c = 0;
    
    for (int i = 0; i < 1000; i++)
        for (int j = 0; j < 1000; j++) 
            if (frequencies[i][j] >= 2) c++;

    cout << "ANS: " << c << endl;
    return 0;
}