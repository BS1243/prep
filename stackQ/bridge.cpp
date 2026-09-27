#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

#include "../basic.h"
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
  int crnttime = 0, crntweight = 0; // answer==time
  queue<pair<int, int>> on_bridge;  // <weight,진입시각>
  queue<int> waiting;

  for (auto x : truck_weights) {
    waiting.push(x);
  }

  while (!on_bridge.empty() || !waiting.empty()) {
    crnttime++;
    //off-the-bridge
    if ((!on_bridge.empty()) &&
        (bridge_length + on_bridge.front().second - crnttime <=
         0)) {
      crntweight -= on_bridge.front().first;
      on_bridge.pop();
    }

    //on-the-bridge
    if ((crntweight < weight) && (!waiting.empty()) &&
        (crntweight + waiting.front() <= weight)) {
      crntweight += waiting.front();
      on_bridge.push(
          {waiting.front(), crnttime}); // crntloc: crnttime - 진입시각
          waiting.pop();
    }
  }

  return crnttime;
}

int main() {
  cout<<solution(100, 100, {10,10,10,10,10,10,10,10,10,10}); // br_lngth , weight, truck_w
}
