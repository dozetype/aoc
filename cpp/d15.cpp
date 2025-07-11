#include "aoc.h"

int res(vector<vector<char>>& map){
    int ans{};
    for(int y=1; y<map.size()-1; y++){
        for(int x=1; x<map[0].size()-1; x++){
            char curr = map[y][x];
            if(curr == 'O'){
                ans += y*100 + x;
            }
        }
    }
    return ans;
}

int main(){
    vector<vector<char>> map;
    ifstream file("puzzles/d15.txt");
    string line;
    array<int, 2> pos; // y, x
    int tempY{}, tempX{};
    bool buildingMap{true};
    unordered_map<char, array<int, 2>> dir = {{'^', {-1, 0}}, {'>', {0, 1}}, {'v', {1, 0}}, {'<', {0, -1}}};
    while(getline(file, line)){
        if(line == "") buildingMap = false;
        
        stringstream ss(line);
        char c;
        if(buildingMap){
            tempX = 0;
            vector<char> row;
            while(ss >> c){
                if(c == '@'){
                    pos = {tempY, tempX};
                    row.push_back('.');
                }
                else row.push_back(c);
                tempX++;
            }
            map.push_back(row);
            tempY++;
        }
        else{
            while(ss >> c){
                // cout << c << endl;
                array<int, 2> nextPos {pos[0]+dir[c][0], pos[1]+dir[c][1]};
                char nextPosItem = map[nextPos[0]][nextPos[1]];
                // cout << nextPos[0] << " " << nextPos[1] << " " << nextPosItem << endl;
                if(nextPosItem == '.'){
                    pos = nextPos;
                }
                else if(nextPosItem == 'O'){
                    array<int, 2> checkPos {nextPos[0]+dir[c][0], nextPos[1]+dir[c][1]};
                    while(true){
                        nextPosItem = map[checkPos[0]][checkPos[1]];
                        if(nextPosItem == '.'){
                            map[nextPos[0]][nextPos[1]] = '.';
                            map[checkPos[0]][checkPos[1]] = 'O';
                            pos = nextPos;
                            break;
                        }
                        else if(nextPosItem == 'O'){
                            checkPos[0]+=dir[c][0];
                            checkPos[1]+=dir[c][1];
                        }
                        else break;
                    }
                }
            }
        }
    }
    
    for(auto i: map){
        for(auto j: i){
            cout << j;
        }
        cout << '\n';
    }
    
    cout << res(map) << endl;
}
