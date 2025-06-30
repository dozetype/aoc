#include "aoc.h"

int main() {
    ifstream file("puzzles/d4.txt");
    vector<vector<char>> puzzle;
    string line;
    int dirs[8][2] = {{0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1}, {-1,0}, {-1,1}};// eight principal wind
    while (getline(file, line)) {
        vector<char> row;
        for (char c: line) row.push_back(c);
        puzzle.push_back(row);
    }
    auto check_bound = [=](int y, int x, auto dir) {return y+dir[0]*3 >= 0 && y+dir[0]*3 < puzzle.size() && x+dir[1]*3 >= 0 && x+dir[1]*3 < puzzle[y].size(); };
    auto check_letters = [=](int y, int x, auto dir) { return puzzle[y+dir[0]][x+dir[1]]=='M' && puzzle[y+dir[0]*2][x+dir[1]*2]=='A' && puzzle[y+dir[0]*3][x+dir[1]*3]=='S'; };
    int ans1{};
    for(int y=0; y<puzzle.size(); y++) for(int x=0; x<puzzle[y].size(); x++) if(puzzle[y][x]=='X') for(const auto dir: dirs) if(check_bound(y, x, dir)) if(check_letters(y, x, dir)) ans1++;
    auto check_bound2 = [=](const int y, const int x) { return y-1 >= 0 && y+1 < puzzle.size() && x-1 >= 0 && x+1 < puzzle[y].size(); };
    constexpr int MAS = 'M' + /* 'A' */ 'S';
    auto check_X = [=](const int y, const int x) { return puzzle[y+dirs[1][0]][x+dirs[1][1]]+puzzle[y+dirs[5][0]][x+dirs[5][1]]==MAS && puzzle[y+dirs[3][0]][x+dirs[3][1]]+puzzle[y+dirs[7][0]][x+dirs[7][1]]==MAS; };
    int ans2{};
    for(int y=0; y<puzzle.size(); y++) for(int x=0; x<puzzle[y].size(); x++) if(puzzle[y][x]=='A') if(check_bound2(y, x)) if(check_X(y, x)) ans2++;
    cout << ans1 << "   " << ans2;
}