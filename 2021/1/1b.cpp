#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> nums;

    int temp;
    while (cin >> temp) {
        nums.push_back(temp);
    }

    int prev = nums[0] + nums[1] + nums[2];
    int curr = -1;
    int count = 0;

    for (int i = 1; i < nums.size() - 2; i++) {
        curr = nums[i] + nums[i+1] + nums[i+2];
        if (curr - prev > 0) {
            count++;
        }

        prev = curr;
    }

    cout << count << endl;

    return 0;
}