#include "aoc.h"

int main(){
    ifstream file("puzzles/d13.txt");
    string line;
    int64_t ans{};
    pair<int64_t, int64_t> a; // button A
    pair<int64_t, int64_t> b; // button B
    pair<int64_t, int64_t> c;
    while(getline(file, line)){
        if(line=="") continue;
        vector<string> currLine;
        istringstream iss(line);
        string token;
        while(iss >> token){
            currLine.push_back(token);
        }

        auto extract = [&](const string& token){
            string s = token;
            if(s.back()==',') s.pop_back();
            return stoll(s.substr(2));
        };
        if(currLine[0]=="Button"){
            if(currLine[1]=="A:"){
                a.first = extract(currLine[2]);
                a.second = extract(currLine[3]);
            }
            else if(currLine[1]=="B:"){
                b.first = extract(currLine[2]);
                b.second = extract(currLine[3]);
            }
        }
        else{
            c.first = extract(currLine[1]) + 10000000000000LL;
            c.second = extract(currLine[2]) + 10000000000000LL;

            // a1*X + b1*Y = c1      X = dx / det
            // a2*X + b2*Y = c2      Y = dy / det
            //
            //         det = a1*b2 - a2*b1
            // dx = c1*b2 - c2*b1    dy = a1*c2 - a2*c1
            long double det = (a.first*b.second) - (a.second*b.first);
            long double dx = (c.first*b.second) - (c.second*b.first);
            long double dy = (a.first*c.second) - (a.second*c.first);
            long double X = dx / det;
            long double Y = dy / det;
            if(abs(X-static_cast<int64_t>(X))<1e-8 && abs(Y-static_cast<int64_t>(Y))<1e-8){
                ans += static_cast<int64_t>(X*3+Y);
            }
        }
    }
    cout << ans << endl;
}
