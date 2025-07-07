#include "aoc.h"

int main(){
    ifstream file("puzzles/d11.txt");
    string line;
    unordered_map<uint64_t, uint64_t> stones;
    while(getline(file, line)){
        stringstream ss(line);
        uint64_t num{};
        while(ss >> num){
            stones[num]++;
        }
    }
    for(int i=0; i<75; i++){
        unordered_map<uint64_t, uint64_t> temp;
        for(const auto& [key, value]: stones){
            string currStone = to_string(key);
            if(key==0){
                temp[1] += value;
            }
            else if(currStone.size()%2==0){
                int half = currStone.size()/2;
                uint64_t firstHalf = stoi(currStone.substr(0, half));
                uint64_t secondHalf = stoi(currStone.substr(half, half));
                temp[firstHalf] += value;
                temp[secondHalf] += value;
            }
            else{
                temp[key*2024] += value;
            }
        }
        stones = temp;
    }
    uint64_t ans{};
    for(const auto& [key, value]: stones){
        ans += value;
    }
    cout << ans << endl;
}
