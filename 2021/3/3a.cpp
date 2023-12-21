#include <bits/stdc++.h>

using namespace std;

int binaryToDecimal(string n)
{
    string num = n;
    int dec_value = 0;
 
    // Initializing base value to 1, i.e 2^0
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
    vector<string> lines;

    while (cin >> line) {
        lines.push_back(line);
    }

    // epsilon string can be built from this string
    string gammaStr = "";

    // loop column first, then row
    for (int j = 0; j < lines[0].size(); j++) {
        int numZeros = 0;
        int numOnes = 0;

        for (int i = 0; i < lines.size(); i++) {
            if (lines[i][j] == '1') {
                numOnes++;
            } else {
                numZeros++;
            }
        }

        if (numZeros > numOnes) {
            gammaStr += '0' ;
        } else {
            gammaStr += '1';
        }
    }


    string epsilonStr = "";

    for (char c : gammaStr) {
        if (c == '0') {
            epsilonStr += '1';
        } else {
            epsilonStr += '0';
        }
    }


    cout << "Gamma: " << gammaStr << endl;
    cout << "Epsilon: " << epsilonStr << endl;

    long long ans = binaryToDecimal(epsilonStr) * binaryToDecimal(gammaStr);

    cout << ans << endl;

    return 0;
}