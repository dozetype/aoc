#include <assert.h>
#include <iostream>
#include <fstream>
#include <regex>
#include <string>

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    std::ifstream file("puzzles/d1.txt");
    assert(file.is_open());

    std::string line;
    std::string token;
    std::vector<int> left;
    std::vector<int> right;
    std::unordered_map<int, int> similarity;
    std::regex delim("\\s"); //delimit all space similar to r"\s"g in python
    while (std::getline(file, line)) {
        std::sregex_token_iterator it(
            line.begin(),
            line.end(),
            delim,
            -1 // special value: return the parts *between* matches. 0 for the matches
        );
        std::sregex_token_iterator end;
        std::vector<int> temp;
        for (; it != end; ++it) {
            if (!it->str().empty()) {
                temp.push_back(stoi(it->str()));
            }
        }
        left.push_back(temp[0]);
        right.push_back(temp[1]);
        similarity[temp[1]]++;
    }
    std::ranges::sort(left);
    std::ranges::sort(right);
    int ans{};
    int ans2{};
    for (int i = 0; i < left.size(); i++) {
        ans += abs(left[i] - right[i]);
        ans2 += similarity[left[i]] * left[i];
    }
    std::cout << ans << "\n" << ans2 << std::endl;
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Elapsed time: " << elapsed.count() << " seconds\n";
    return 0;
}