#include "aoc.h"

struct vec {
    int x{};
    int y{};
};

int main() {
    auto start = Clock::now();
    
    vector<vec> poss;
    vector<vec> vels;
    ifstream file("puzzles/d14.txt");
    string line;
    while (getline(file, line)) {
        stringstream ss{line};
        string sec;
        while (ss >> sec) {
            int commaPos = sec.find(',');
            int x = stoi(sec.substr(2, commaPos - 2));
            int y = stoi(sec.substr(commaPos + 1));
            if (sec[0] == 'p') {
                poss.push_back(vec(x, y));
            } else {
                vels.push_back(vec(x, y));
            }
        }
    }
    int width{101};
    int height{103};
    int halfW{width / 2};
    int halfH{height / 2};
    int n = poss.size();
    int q1{}, q2{}, q3{}, q4{};
    set<pair<int, int>> uniquePos;
    int sec{0};
    while (uniquePos.size() != n) {
        int lastSize{0};
        sec++;
        uniquePos.clear();
        for (int i = 0; i < n; i++) {
            int x = ((poss[i].x + vels[i].x * sec) % width + width) % width;
            int y = ((poss[i].y + vels[i].y * sec) % height + height) % height;
            if (sec == 100) {
                if (x < halfW && y < halfH) q1++;
                else if (x < halfW && y > halfH) q2++;
                else if (x > halfW && y < halfH) q3++;
                else if (x > halfW && y > halfH) q4++;
            }
            uniquePos.insert({x, y});
            if(uniquePos.size() == lastSize) break;
            lastSize++;
        }
    }
    for(int x=0; x<width; x++){ // Easter Egg
        for(int y=0; y<height; y++){
            auto it = uniquePos.find({x, y});
            if(it != uniquePos.end()) cout << 'x';
            else cout << '.';
        }
        cout << '\n';
    }
    
    cout <<"part1: " << q1 * q2 * q3 * q4 << ", part2: " << sec << endl;
    
    duration<double> elapsed = Clock::now() - start;
    cout << elapsed.count() << " sec" << endl;
}
