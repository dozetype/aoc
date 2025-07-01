#include "aoc.h"

int main() {
    ifstream file("puzzles/d5.txt");
    /**  rules:
     *   56: 61 23 28 29 75 44 32 57 14 98 11 94 69 85 68 53 84 17 27 62 89 81 74 72
     *   21: 35 14 44 84 24 83 17 99 46 94 48 81 56 82 68 49 73 77 43 85 32 16 95 33
     */
    unordered_map<int, vector<int>> rules;
    string line;
    bool firstPortion = true;
    int ans1{}, ans2{};
    while (getline(file, line)) {
        if (line == "") {
            firstPortion = false;
            continue;
        }

        stringstream ss(line);
        char delimeter{};
        if (firstPortion) {
            int num1{}, num2{};
            ss >> num1 >> delimeter >> num2;
            rules[num1].push_back(num2);
        }
        else {
            //update: 29,39,24,43,77,33,82
            vector<int> update;
            int num;
            while (ss >> num) {
                update.push_back(num);
                ss >> delimeter;
            }
            bool ok = true;
            for (int i=0; i<update.size()-1; i++) {
                for (int j=i+1; j<update.size(); j++) {
                    if (auto& curr = rules[update[j]]; find(curr, update[i]) != curr.end()) {
                        ok = false;
                        int value = update[j];
                        update.erase(update.begin()+j);
                        update.insert(update.begin()+i, value);
                    }
                }
            }
            if (ok) ans1 += update[update.size()/2];
            else ans2 += update[update.size()/2];
        }
    }
    cout << ans1 << "   " << ans2 << endl;
    DebugLog("hello");
}