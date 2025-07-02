#include "aoc.h"

int main() {
    auto start = Clock::now();
    ifstream file("puzzles/d7.txt");
    string line;
    long long ans{};
    while (getline(file, line)) {
        stringstream ss(line);
        long long goal{};
        char delim;
        ss >> goal >> delim; //pulling "int" and ":"
        vector<int> nums;
        int num{};
        while (ss >> num) { //pulling "int"s
            nums.push_back(num);
        }

        function<bool(long long, int)> check = [&](const long long curr, const int index) {
            if (nums.size() == index) return curr==goal;

            return check(curr*nums[index], index+1) ||
               check(curr+nums[index], index+1) ||
                   check(stoll(to_string(curr)+to_string(nums[index])), index+1);
        };

        if (check(nums[0], 1)) {
            ans += goal;
        }
    }
    duration<double> elapsed = Clock::now() - start;
    cout << elapsed.count() << endl;
    cout << ans << endl;
}