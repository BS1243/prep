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
int cnt = 0;

void dfs(int left, int right, int eval) {
  if (left == 0 && right == 0)
    cnt++;
  if (right >= 1 && eval >= 1)
    dfs(left, right - 1, eval - 1);
  if (left >= 1)
    dfs(left - 1, right, eval + 1);
}

int solution(int n) {
  dfs(n, n, 0);
  return cnt;
}

int main() {
  int n = 6;
  cout<<solution(3);
}
