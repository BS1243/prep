#include <iostream>
#include <stack>
#include <vector>
#include "../basic.h"
using namespace std;

vector<int> solution(vector<int> prices) {
  vector<int> answer(prices.size(), 0);
  stack<pair<int, int>> st; // price,time

  for (int i = 0; i < prices.size(); i++) {
    while ((!st.empty()) && (st.top().first > prices[i])) {
      answer[st.top().second] = i - st.top().second;
      st.pop();
    }
    st.push({prices[i], i});
  }

  while(!st.empty()){
    answer[st.top().second]=prices.size()-st.top().second-1;
    st.pop();
  }

  return answer;
}

int main() {
  vector<int> prices = {1, 2, 3, 2, 3};//43110

  vector<int> result = solution(prices);

  for (int x : result) {
    cout << x << ' ';
  }
}