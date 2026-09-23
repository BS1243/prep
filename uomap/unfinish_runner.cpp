#include "basic.h"
#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
  string answer = "";
  unordered_map<string, int> table; // name,int

  for (auto row : participant) {
    if (table.find(row) != table.end()) {
      table[row]++;
    } else {
      table[row] = 1;
    }
  }
  for (auto row : completion) {
    table[row]--;
  }

  for (auto row : table) {
    if (row.second >= 1)
      answer = row.first;
  }
  return answer;
}

int main() {
  int n = 6;
  vector<string> pp = {"marina", "josipa", "nikola", "vinko", "filipa"};
  vector<string> cp = {"josipa", "filipa", "marina", "nikola"};

  solution(pp, cp);
}
