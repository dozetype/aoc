#include "aoc.h"

int main() {
    ifstream file("puzzles/d3.txt");
    regex delim(R"((mul\(\d+,\d+\))|(don\'t\(\))|(do\(\)))");
    regex inner_delim(R"(^mul\((\d+),(\d+)\))");
    sregex_token_iterator end;
    string line;
    int ans1{}, ans2{};
    vector<string> all_search;
    while (getline(file, line)) {
        sregex_token_iterator it(
            line.begin(),
            line.end(),
            delim,
            0 // special value: return the parts *between* matches. 0 for the matches
        );
        for (; it != end; ++it) {
            all_search.push_back(it->str());
        }
    }
    bool on = true;
    for (auto x: all_search) {
        if (!(x=="don't()" || x=="do()")) {
            if (smatch match; regex_match(x, match, inner_delim)) {
                ans1 += stoi(match[1]) * stoi(match[2]);
            }
        }
        if (on && !(x=="don't()" || x=="do()")) {
            if (smatch match; regex_match(x, match, inner_delim)) {
                ans2 += stoi(match[1]) * stoi(match[2]);
            }
        }
        else if (x=="do()") {
            on = true;
        }
        else if (x=="don't()") {
            on = false;
        }
    }
    cout << ans1 << "  " << ans2 << endl;
}