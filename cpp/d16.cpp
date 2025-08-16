#include "aoc.h"

struct Node{
    int dist{INT_MAX};
    pair<int, int> prev;
    bool wall;
    
    Node(bool isWall = false):wall(isWall){};
};

int lol(vector<vector<Node>>& maze, array<int, 2> currPos, int dir);

int main(){
    ifstream file("puzzles/d16.txt");
    string line;
    vector<vector<Node>> maze;
    array<int, 2> startPos;
    int currDir = 3;
    array<int, 2> endPos;
    int x{}, y{};
    array<array<int, 2>, 4> dirs = {{{-1,0}, {0,-1}, {1,0}, {0,1}}};
    while(getline(file, line)){
        x = 0;
        stringstream ss(line);
        char c;
        vector<Node> currLine;
        while(ss >> c){
            if(c == 'S') startPos = {y, x};
            else if(c == 'E') startPos = {y, x};
            if(c != '#') currLine.emplace_back(Node(false));
            else currLine.emplace_back(Node(true));
        }
        maze.push_back(currLine);
        ++y;
    }
    array<int, 2> currPos = startPos;
}

int lol(vector<vector<Node>>& maze, array<int, 2> currPos, int dir){
    if(maze[currPos[0]][currPos[1]].wall) return ;
}
