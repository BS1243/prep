
//#include "../basic.h"
#include <algorithm>
#include <array>
#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;

int cal(int n) {
  int total = 0;
  while (n > 0) {
    int digit = n % 10;
    total += digit * digit;
    n /= 10;
  }
  return total;
}

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> graph(n, vector<int>(1001));
  for (int i = 0; i < n; i++) {
    cin >> graph[i][0];
  }
  for (int i = 1; i < 1001; i++) {
    for (int j = 0; j < n; j++) {
      graph[j][i] = cal(graph[j][i - 1]);
    }
  }
  int total = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      if (i == j)
        continue;
      if (graph[i][1000] == graph[j][1000])
        total++;
    }
  }
  cout << total << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}

/**
4
5
7 4 16 4 2
4
1 7 10 100
3
4 16 37
3
2 20 4
 tc
 n
 cases>>
**/
