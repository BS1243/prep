
#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include "../basic.h"

using namespace std;

int solution(vector<vector<int>> maps) {
  queue<pair<int, int>> q;
  vector<vector<int>> dist;
  q.push({0, 0}); // Y X

  dist = maps;

  while (!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop();
    // cout << cur.first << cur.second << endl;

    if ((cur.first == maps.size() - 1) && (cur.second == maps[0].size() - 1)) {
      return dist[cur.first][cur.second];
    }

    if (cur.first + 1 < maps.size() && maps[cur.first + 1][cur.second] == 1) {

      q.push({cur.first + 1, cur.second});
      dist[cur.first + 1][cur.second] = dist[cur.first][cur.second] + 1;
      maps[cur.first + 1][cur.second] = 0;
    }

    if (cur.first - 1 >= 0 && maps[cur.first - 1][cur.second] == 1) {

      q.push({cur.first - 1, cur.second});
      dist[cur.first - 1][cur.second] = dist[cur.first][cur.second] + 1;
      maps[cur.first - 1][cur.second] = 0;
    }

    if (cur.second + 1 < maps[0].size() &&
        maps[cur.first][cur.second + 1] == 1) {

      q.push({cur.first, cur.second + 1});
      dist[cur.first][cur.second + 1] = dist[cur.first][cur.second] + 1;
      maps[cur.first][cur.second + 1] = 0;
    }

    if (cur.second - 1 >= 0 && maps[cur.first][cur.second - 1] == 1) {

      q.push({cur.first, cur.second - 1});
      dist[cur.first][cur.second - 1] = dist[cur.first][cur.second] + 1;
      maps[cur.first][cur.second - 1] = 0;
    }
  }
  return -1;
}

int main() {
  int n = 6;
  vector<vector<int>> maps = {{1, 0, 1, 1, 1},
                              {1, 0, 1, 0, 1},
                              {1, 0, 1, 1, 1},
                              {1, 1, 1, 0, 1},
                              {0, 0, 0, 0, 1}};
  cout << solution(maps);
}
