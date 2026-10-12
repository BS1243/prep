#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

#include "../basic.h"
using namespace std;
int cnt = 0, targetn;
vector<int> ln;
// 4121 , 4

void dfs(int crnt, int depth, int promising, vector<int> g) {
  cout << crnt << depth << endl;
  if (depth == g.size()) {
    if (targetn == crnt)
      cnt++;
    return;
  }

  if ((crnt - promising > targetn) || (crnt + promising < targetn))
    return;

  dfs(crnt + g[depth], depth + 1, promising - g[depth], g);
  dfs(crnt - g[depth], depth + 1, promising - g[depth], g);
}

int solution(vector<int> numbers, int target) {
  targetn = target;
  int leftnum = accumulate(numbers.begin(), numbers.end(), 0);
  sort(numbers.begin(), numbers.end(), [](auto &a, auto &b) { return a > b; });
  dfs(0, 0, leftnum, numbers);
  return cnt;
}

int main() {
  int n = 6;
  vector<int> edge = {4, 1, 2, 1};

  cout << solution(edge, 4);
}
