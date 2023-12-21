#include <bits/stdc++.h>

using namespace std;

struct Board {
    int A[5][5];    // the board
    bool B[5][5];   // whether spot on board is marked
    bool solved = false;

    bool read() {
        for (int i = 0; i < 5; i++){
            for (int j = 0; j < 5; j++) {
                if (!(cin >> A[i][j])) {
                    return false;
                }
                B[i][j] = false;
            }
        }
        return true;
    }

    void debug() {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j <5; j++) {
                if (B[i][j]) {
                    cout << "1 ";
                } else {
                    cout << "0 ";
                }
            }
            cout << endl;
        }
        cout << endl;
    }
};

// Checks if at least one row or column fully marked
bool bingo(const Board& board) {
    // Check rows
    for (int i = 0; i < 5; i++) {
        int x = 0;
        for (int j = 0; j < 5; j++) {
            if (board.B[i][j]) x++;
        }
        if (x == 5) return true;
    }

    // Check columns
    for (int j = 0; j < 5; j++) {
        int x = 0;
        for (int i = 0; i < 5; i++) {
            if (board.B[i][j]) x++; 
        }
        if (x == 5) return true; // at least one col is good
    }

    // exhausted every row and column and none was full
    return false;
}

void mark(Board& board, int draw) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (board.A[i][j] == draw) {
                board.B[i][j] = true;
            }
        }
    }
}

int sum(const Board& board) {
    int res = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (!board.B[i][j]) {
                res += board.A[i][j];
            }
        }
    }
    return res;
}

int main() {
    string input;
    getline(cin, input);
    replace(begin(input), end(input), ',', ' ');
    istringstream iss(input);
    
    vector<int> nums;
    int x;
    while (iss >> x) {
        nums.push_back(x);
    }

    vector<Board> boards;
    Board B;

    while (B.read()) {
        boards.push_back(B);
    }

    for (Board b: boards) {
        b.debug();
    }

    int numBoards = boards.size();
    int numSolved = 0;

    for (int draw: nums) {
        for (int i = 0; i < boards.size(); i++) {
            mark(boards[i], draw);
            if (bingo(boards[i])) {
                if (!boards[i].solved) {
                    boards[i].solved = true;
                    if (numBoards - numSolved == 1) {
                        int ans = sum(boards[i]) * draw;
                        cout << "ANS: " << ans << endl;
                    }
                    numSolved++;

                }
            }
        }
    }

    
    
    return 0;
}