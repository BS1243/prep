#include <algorithm>
#include <set>
#include <string>
#include <vector>


using namespace std;

set<int> nums;

bool isPrime(int n) {
  if (n < 2)
    return false;

  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0)
      return false;
  }

  return true;
}

void dfs(string numbers, string cur, vector<bool> &visited) {
  if (!cur.empty())
    nums.insert(stoi(cur));

  for (int i = 0; i < numbers.size(); i++) {
    if (visited[i])
      continue;

    visited[i] = true;

    dfs(numbers, cur + numbers[i], visited);

    visited[i] = false;
  }
}

int solution(string numbers) {
  nums.clear();

  vector<bool> visited(numbers.size(), false);

  dfs(numbers, "", visited);

  int answer = 0;

  for (int n : nums) {
    if (isPrime(n))
      answer++;
  }

  return answer;
}