#include "aoc.h"

int main(){
    ifstream file("puzzles/d16.txt");
    string line;
    vector<vector<char>> maze;
    while(getline(file, line)){
        stringstream ss(line);
        char c;
        vector<char> currLine;
        while(ss >> c){
            currLine.push_back(c);
        }
        maze.push_back(currLine);
    }
    for(auto i: maze){
        for(auto x: i){
            cout << x;
        }
        cout << "\n";
    }
}
