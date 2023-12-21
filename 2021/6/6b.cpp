#include <bits/stdc++.h>

using namespace std;

typedef unordered_map<int, long long> mp;

void debug(mp fish, int day) {
    cout << "AFTER DAY " << day << endl;
    for (const auto &pair : fish) {
        cout << pair.first << " " << pair.second << endl;
    }
}

int main() {
    string s;
    cin >> s;
    std::replace(s.begin(), s.end(), ',', ' ');                      
    stringstream ss(s);

    mp daysToFish;

    for (int n; ss >> n;) 
       daysToFish[n]++;

    int days = 0;

    while (days < 256) {
        mp temp;
        for (int i = 0; i <= 8; i++) temp[i] = 0;

        for (const auto &pair: daysToFish) {
            int key = pair.first;
            if (key == 0) {
                temp[6] += daysToFish[key];
                temp[8] = daysToFish[key];
            } else {
                temp[key - 1] += daysToFish[key];
            }
        }

        daysToFish = temp;

        days++;
    }

    long long ans = 0;
    for (const auto& p : daysToFish) {
        ans += p.second;
    }

    cout << ans << endl;

    return 0;
}