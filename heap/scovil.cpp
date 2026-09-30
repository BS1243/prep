#include "../basic.h"
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int solution(vector<int> scoville, int K) {
  int answer = 0;
  priority_queue<int, vector<int>, greater<int>> pq;

  for (auto x : scoville) {
    pq.push(x);
  }

  int first;
  while (!pq.empty()) {
    if (pq.top() >= K) {
      pq.pop();
      continue;
    }
    answer++;
    first = pq.top();
    pq.pop();
    if (pq.empty())
      return -1;
    first = pq.top() * 2 + first;
    pq.pop();
    pq.push(first);
  }
  return answer;
}

int main() { cout << solution({1, 2, 3, 9, 10, 12}, 7); }
