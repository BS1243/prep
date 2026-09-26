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

bool solution(string s) {
  int cnt = 0;
  bool answer = true;
  for (int i = 0; i < s.size(); i++) {
    s[i] == '(' ? cnt++ : cnt--;
    if (cnt < 0) {
      answer = false;
      break;
    }
  }
  if (cnt != 0)
    answer = false;
  return answer;
}


int main() { cout<<solution(")()("); }
