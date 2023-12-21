#include <iostream>
#include <fstream>

using namespace std;

int main() {
    int YEARS[200];
    ifstream fileIn("input.txt");
    if (fileIn.is_open()) {
        fileIn >> YEARS[0];
        int count = 1;
        while (!fileIn.eof()) {
            fileIn >> YEARS[count];
            count++;
        }
    } else {
        cerr << "Could not open file" << endl;
    }

    for (int i = 0; i < 200; i++) 
        for (int j = i+1; j < 200; j++) 
            if (YEARS[i] + YEARS[j] == 2020) 
                cout << YEARS[i] * YEARS[j] << endl;

    for (int i = 0; i < 200; i++)
        for (int j = i+1; j < 200; j++)
            for (int k = j+1; k < 200; k++)
                if (YEARS[i] + YEARS[j] + YEARS[k] == 2020)
                    cout << YEARS[i] * YEARS[j] * YEARS[k] << endl;
    
    return 0;
}