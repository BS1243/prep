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

vector<int> solution(vector<int> progresses, vector<int> speeds) {
  vector<int> answer;

  int i = 0;
  int total = 0;

  while (total != speeds.size()) {

    while (progresses[total] + speeds[total] * i < 100) {
      i++;
    }
    int ps = 0;
    while (total < speeds.size() &&
           progresses[total] + speeds[total] * i >= 100) {
      ps++;
      total++;
    }
    answer.push_back(ps);
  }

  return answer;
}

int main() {
  int n = 6;
  vector<int> e1 = {93, 30, 55};
  vector<int> e2 = {1, 30, 5};
  pr1(solution(e1, e2));
}
