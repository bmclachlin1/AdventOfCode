#include <bits/stdc++.h>

using namespace std;

void debug(vector<int> fish, int day) {
    cout << "AFTER DAY " << day << ": ";
    for (int n : fish) cout << n << ",";
    cout << endl; 
}

int main() {
    string s;
    cin >> s;
    std::replace(s.begin(), s.end(), ',', ' ');                      
    stringstream ss(s);
    vector<int> fish;

    for (int n; ss >> n;) 
       fish.push_back(n);

    int days = 0;
    while (days < 80) {
        int N = fish.size();
        for (int i = 0; i < N; i++) {
            if (fish[i] == 0) {
                fish[i] = 6;
                fish.push_back(8);
            } else {
                fish[i]--;
            }
        }
        days++;
    }

    cout << fish.size() << endl;

    return 0;
}