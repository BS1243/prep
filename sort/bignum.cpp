#include "../basic.h"
#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<vector<int>> map;

string solution(vector<int> numbers) {
  string answer = "";
  bool check=true;
  vector<string> strnum;
  for (int x : numbers) {
    if(x!=0) check=false;
    strnum.push_back(to_string(x));
  }
  sort(strnum.begin(), strnum.end(),
       [](auto &a, auto &b) { return a + b > b + a; });
  for (string x : strnum) {
    answer += x;
  }
  if(check) answer="0";
  return answer;
}

int main() {
  int n = 6;
  vector<int> edge = {0,0,0,0};

  cout<<solution(edge);
}
