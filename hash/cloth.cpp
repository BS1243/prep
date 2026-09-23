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

int solution(vector<vector<string>> clothes) {
  // 옷 이름 , 종류
  int answer = 1;

  unordered_map<string, int> table; // name,int

  for (auto row : clothes) {
    if (table.find(row[1]) != table.end()) {
      table[row[1]]++;
    } else {
      table[row[1]] = 1;
    }
  }

  for (auto row : table) {
    answer = answer * (row.second + 1);
  }
  return answer - 1;
}

int main() {
  int n = 6;
  vector<vector<string>> clothes = {{"yellow_hat", "headgear"},
                                    {"blue_sunglasses", "eyewear"},
                                    {"green_turban", "headgear"}};

  cout << solution(clothes);
}
