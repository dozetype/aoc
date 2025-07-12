#include "aoc.h"

int res(vector<vector<char>>& map){
    int ans{};
    for(int y=1; y<map.size()-1; y++){
        for(int x=2; x<map[0].size()-2; x++){
            char curr = map[y][x];
            if(curr == '['){
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
                if(c == '.'){
                    row.push_back('.');
                    row.push_back('.');
                }
                else if(c == '#'){
                    row.push_back('#');
                    row.push_back('#');
                }
                else if(c == 'O'){
                    row.push_back('[');
                    row.push_back(']');
                }
                else{
                    pos = {tempY, tempX};
                    row.push_back('.');
                    row.push_back('.');
                    cout << "Start Pos "<<pos[0] << " "<< pos[1] << '\n';
                }
                tempX += 2;
            }
            map.push_back(row);
            tempY++;

        }
        else{
            //what i need to do is to first check if ive found [ or ] then push it in, then push the other one in too. then move forward by 1, then push other one in as well
            while(ss >> c){
                // cout << c << endl;
                array<int, 2> nextPos {pos[0]+dir[c][0], pos[1]+dir[c][1]};
                char nextPosItem = map[nextPos[0]][nextPos[1]];
                // cout << nextPos[0] << " " << nextPos[1] << " " << nextPosItem << endl;
                if(nextPosItem == '.'){
                    pos = nextPos;
                }
                else if(nextPosItem == '[' || nextPosItem == ']'){
                    queue<array<int, 2>> q; //queue to hold pos to check
                    set<array<int, 2>> qSet;
                    q.push(nextPos);
                    qSet.insert(nextPos);
                    if(nextPosItem == '[') {q.push({nextPos[0], nextPos[1]+1}); qSet.insert({nextPos[0], nextPos[1]+1});}
                    else {q.push({nextPos[0], nextPos[1]-1}); qSet.insert({nextPos[0], nextPos[1]+1});}
                    bool movable{true};
                    while(!q.empty()){
                        array<int, 2> currPos = q.front();
                        q.pop();
                        currPos[0]+=dir[c][0];
                        currPos[1]+=dir[c][1];
                        nextPosItem = map[currPos[0]][currPos[1]];
                        if(nextPosItem == '.') continue;
                        else if(nextPosItem == '[' || nextPosItem == ']'){
                            q.push(currPos);
                            qSet.insert(currPos);
                            if(nextPosItem == '['){
                                if(!qSet.contains({currPos[0], currPos[1]+1})){
                                    q.push({currPos[0], currPos[1]+1});
                                    qSet.insert({currPos[0], currPos[1]+1});
                                }
                            }
                            else {
                                if(!qSet.contains({currPos[0], currPos[1]-1})){
                                    q.push({currPos[0], currPos[1]-1});
                                    qSet.insert({currPos[0], currPos[1]-1});
                                }
                            }
                        }
                        else{
                            movable = false;
                            break;
                        }
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
