#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

#include "../basic.h"
using namespace std;

int solution(vector<int> citations) {
  int answer;
  sort(citations.begin(), citations.end(),
       [](auto &a, auto &b) { return a > b; });
  int i = 0;
  for (i = 0; i < citations.size(); i++) {
    if (citations[i] < i + 1)
      break;
  }
  return i;
}

int main() {
  vector<int> edge = {2, 3, 4, 5, 6};
  cout << solution(edge);
}
