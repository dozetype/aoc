#include "aoc.h"

bool isGood(vector<int> path) {
    bool only_inc{true};
    bool only_dec{true};
    bool safe{true};
    for (int i=0; i<path.size()-1; i++) {
        int diff = path[i+1]-path[i];
        if (diff>0) {
            only_dec = false;
        }
        if (diff<0) {
            only_inc = false;
        }
        if (abs(diff)<1 || abs(diff)>3) {
            safe = false;
            break;
        }
    }
    return safe && (only_dec||only_inc);
}

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    ifstream file("puzzles/d2.txt");
    string line;
    int safe_count{};
    while (getline(file, line)) {
        vector<int> curr_path;
        istringstream iss(line);
        int num;
        while (iss >> num) {
            curr_path.push_back(num);
        }

        bool anyOk = isGood(curr_path); //check without removing
        auto consider = [&](int i) { //anonymous for removing index i and checking
            vector<int> path = curr_path;
            path.erase(path.begin() + i);
            if (isGood(path)) {
                anyOk = true;
            }
        };
        if (!anyOk) {
            for (int i=0; i<curr_path.size()-1; i++) {
                int diff = curr_path[i+1] - curr_path[i];
                //Only gonna check if the one error found can be salvaged
                if (abs(diff)<1 || abs(diff)>3) { //if diff>3 or diff==0
                    consider(i);
                    consider(i+1);
                    break;
                }
                if (i+2 < curr_path.size()) {
                    int diff2 = curr_path[i+2]-curr_path[i+1];
                    if ((diff>0) != (diff2>0)) { //if up and down
                        consider(i);
                        consider(i+1);
                        consider(i+2);
                        break;
                    }
                }
            }
        }
        if (anyOk) safe_count++;
    }
    cout << safe_count << endl;
    auto end = std::chrono::high_resolution_clock::now();
    duration<double> elapsed = end - start;
    cout << "Elapsed time: " << elapsed.count() << " seconds\n";
}
