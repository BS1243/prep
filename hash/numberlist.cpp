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

int solution(vector<string> nums) {
  sort(nums.begin(), nums.end());
  bool answer = true;
  for (int i = 1; i < nums.size(); i++) {
    if (!nums[i].compare(0, nums[i - 1].size(), nums[i - 1])) // compare 같으면
                                                              // 0
      answer = false;
  }

  return answer;
}

int main() {
  vector<string> nums = {"12", "123", "1235", "567", "88"};
  cout << solution(nums);
}