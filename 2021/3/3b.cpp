#include <bits/stdc++.h>

using namespace std;

int binaryToDecimal(string n)
{
    string num = n;
    int dec_value = 0;
    int base = 1;
 
    int len = num.length();
    for (int i = len - 1; i >= 0; i--) {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }
 
    return dec_value;
}

int main() {
    string line;
    vector<string> lines; // don't mutate original array

    while (cin >> line) {
        lines.push_back(line);
    }

    sort(lines.begin(), lines.end());

    // restrict search space
    int lo = 0, hi = lines.size();

    string oxygen;
    string co2;

    for (int j = 0; j < lines[0].size(); j++) {
        if (abs(lo-hi) <= 1) {
            oxygen = lines[lo];
            break;
        }

        int zeros = 0, ones = 0;
        int firstOne = INT_MAX; // keep track of first non-zero bit

        for (int i = lo; i < hi; i++) {
            if (lines[i][j] == '0') zeros++;
            else {
                ones++;
                firstOne = min(firstOne, i);
            }
        }

        if (ones >= zeros) {
            lo = firstOne;
        } else {
            hi = firstOne;
        }
    }

    oxygen = lines[lo];

    lo = 0;
    hi = lines.size();

    for (int j = 0; j < lines[0].size(); j++) {
        if (abs(lo-hi) <= 1) {
            co2 = lines[lo];
            break;
        }

        int zeros = 0, ones = 0;
        int firstOne = INT_MAX; // keep track of first non-zero bit

        for (int i = lo; i < hi; i++) {
            if (lines[i][j] == '0') zeros++;
            else {
                ones++;
                firstOne = min(firstOne, i);
            }
        }

        if (ones >= zeros) {
            hi = firstOne;
        } else {
            lo = firstOne;
        }
    }

    co2 = lines[lo];


    cout << "ANSWER: " << binaryToDecimal(oxygen) * binaryToDecimal(co2) << endl;

    return 0;
}