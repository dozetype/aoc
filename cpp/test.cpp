#include "aoc.h"

int main() {
    int num = 100;
    auto eve = [](const int i) {
        return i%2==0;
    };
    auto range = iota(0, num) | filter(eve);
    std::cout << accumulate(range.begin(), range.end(), 0) << std::endl;

    int a = 5;
    int b = 10;

    auto f = [&](const int x) {
        std::cout << a <<" "<<b<<" "<<x<<std::endl;
        return a + b + x;
    };
    f(3);
    a++;
    b++;
    f(4);

    vector<int> hello = {1,2,3};
    if (hello[-1]) {
        cout << "nice";
    }
}
