#include "aoc.h"

int main() {
    ifstream file("puzzles/d5.txt");
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
}