#include <bits/stdc++.h>

using namespace std;

void debug(const vector<int>& elems) {
    for (int n: elems) cout << n << endl;
}

int main() {
    string s;
    cin >> s;
    replace(s.begin(), s.end(), ',', ' ');      
    stringstream ss(s);

    vector<int> dx;

    for (int n; ss >> n;) 
       dx.push_back(n);

    int maxPos = *max_element(dx.begin(), dx.end());

    int ans = INT_MAX;
    for (int pos = 0; pos < maxPos; pos++) {
        int curr = 0;
        for (int crab: dx) {
            int dist = abs(pos - crab);
            int cost = (dist * (dist + 1)) / 2; // summation of first N elements
            curr += cost;
        }
        ans = min(ans, curr);
    }

    cout << ans << endl;

    return 0;
}