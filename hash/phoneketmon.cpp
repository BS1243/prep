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

vector<vector<int>> map;

int solution(vector<int> nums) {
  sort(nums.begin(), nums.end());
  int answer = 1, prv = nums[0], total = nums.size() / 2;

  for (auto row : nums) {
    if (answer == total)
      break;
    if (row == prv) {
      continue;
    }
    answer++;
    prv = row;
  }

  return answer;
}

int main() { vector<int> nums = {3, 1, 2, 3}; }