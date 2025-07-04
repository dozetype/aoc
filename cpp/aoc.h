#ifndef AOC_H
#define AOC_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <numeric>
#include <ranges>
#include <regex>
#include <unordered_set>
#include <set>
#include <chrono>
#include <utility>
#include <algorithm>
#include <climits>

#define DebugLog( msg )  std::cout << __FILE__ << ":" << __LINE__ << ": " << msg

using std::ifstream;
using std::istringstream;
using std::stringstream;
using std::chrono::duration;
using std::vector;
using std::unordered_map;
using std::unordered_set;
using std::map;
using std::string;
using std::regex;
using std::sregex_token_iterator;
using std::smatch;
using std::pair;
using std::set;
using std::bitset;

using Clock = std::chrono::high_resolution_clock;
using std::cout;
using std::endl;
using std::views::iota;
using std::views::filter;
using std::accumulate;
using std::stoi;
using std::stoll;
using std::regex_match;
using std::ranges::find;
using std::make_pair;
using std::to_string;
using std::function;
using std::swap;


#endif //AOC_H
