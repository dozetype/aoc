#include "cpp/aoc.h"

int main(){
    array<array<int, 2>, 4> dirs = {{{-1, 0}, {0, -1}, {1, 0}, {0, 1}}};
    array<int, 2> arr = {{-1,0}};
    auto it = find(dirs.begin(), dirs.end(), arr);
    cout<< std::ranges::distance(dirs.begin(), it) << endl;

}
