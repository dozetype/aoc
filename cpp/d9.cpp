#include <climits>

#include "aoc.h"

int main() {
    auto start = Clock::now();

    /**
     * READING
     */
    ifstream file("puzzles/d9.txt");
    string line;
    vector<int> nums;
    unordered_map<int, int> len;
    while (getline(file, line)) {
        for (char c : line) {
            nums.push_back(c - '0');
        }
    }
    /**
     * SETTING UP
     */
    vector<int> blocks;
    for (int i = 0; i < nums.size(); i++) {
        int ch{};
        if (i % 2 == 0)
            ch = i / 2;
        else
            ch = INT_MAX;
        for (int j = 0; j < nums.at(i); j++) {
            blocks.push_back(ch);
        }
        if (ch != INT_MAX) {
            len[ch] = nums.at(i);
        }
    }
    ///////////////////////////////////////Part 1//////////////////////////////////////
    // int j=blocks.size()-1;
    // for(int i=0; i<blocks.size(); i++){
    //     if(blocks.at(i) == INT_MAX){
    //         for(; j>i; j--){
    //             if(blocks.at(j)!=INT_MAX){
    //                 swap(blocks[i], blocks[j]);
    //                 break;
    //             }
    //         }
    //     }
    // }

    /////////////////////////////////////////Part 2///////////////////////////////
    int startPos{};
    int quickStart{};  // HEADSTART FOR J Loop
    for (int i = blocks.size() - 1; i >= 0; i--) {
        if (blocks.at(i) != INT_MAX) {
            int neededSize = len[blocks.at(i)];
            bool newStart{true};
            bool quickFlag{true};  // HEADSTART
            for (int j = quickStart; j < i; j++) {
                if (blocks.at(j) != INT_MAX) {
                    newStart = true;
                    if (quickFlag) {  // HEADSTART
                        quickStart = j;
                    }
                    continue;
                } else if (newStart && blocks.at(j) == INT_MAX) {
                    startPos = j;
                    newStart = false;
                    quickFlag = false;  // HEADSTART
                }
                if (blocks.at(j) == INT_MAX && (j - startPos + 1) >= neededSize) {
                    for (int k = 0; k < neededSize; k++) {
                        swap(blocks[i + k - (neededSize - 1)], blocks[startPos + k]);
                    }
                    break;
                }
            }
        }
    }

    ////////////////////////////////////////////////////////////////////////////

    long long ans{};
    for (int i = 1; i < blocks.size(); i++) {
        if (blocks.at(i) == INT_MAX) continue;
        ans += ((blocks.at(i)) * i);
    }
    cout << ans << '\n';

    duration<double> elapsed = Clock::now() - start;
    cout << elapsed.count() << " sec" << endl;
}
