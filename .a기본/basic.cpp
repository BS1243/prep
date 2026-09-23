#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

// git add .
// git commit -m "설명"
// git push
// git pull
int main() {
  cout << "안녕!\n";
  return 0;
}

vector<int> v(10);
vector<int> v(10, -1); // 값 전부 -1
vector<vector<int>> v(3,
                      vector<int>(4, -1)); // 3 X (4)인 벡터 3 X (-1,-1,-1,-1)

for (int i = 0; i < 5; i++) {
  cin >> v[i];
} // 입력

for (int x : v) {
  cout << x << " ";
} // 1d 출력

for (auto row : v) {
  for (int x : row) {
    cout << x << " ";
  }
  cout << '\n';
} // 2d 출력

for (auto row : v) {
  int a = row[0];
  int b = row[1];
} // 2d 꺼내기

adj.resize(n + 1); // resize

vector<vector<int>> graph(n); // nX(빈칸)
graph[a].push_back(b);        // a열에 b 넣기
'' for (int next : graph[3])  // 꺼내기
{
  cout << next << ' ';
} // 인접 리스트(2차원 리스트)

void handleRecord(vector<string> record) {

  for (string str : record) {

    string cmd;
    string id;
    string nickname;

    stringstream ss(str);

    ss >> cmd >> id;

    if (cmd != "Leave") {
      ss >> nickname;
    }

    // 여기까지 오면
    // Enter  -> cmd, id, nickname
    // Leave  -> cmd, id
    // Change -> cmd, id, nickname
  }

  unordered_map<string, string> uomap; // ID-> nickname
  uomap[id] = nickname;
  if (uomap.find("marina") != uomap.end()) // 있음
  if (uomap.find(row) == uomap.end())    // 없음