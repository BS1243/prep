#include "basic.h"
#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

//["Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234
// Prodo","Change uid4567 Ryan"]

vector<string> solution(vector<string> record) {
  vector<vector<string>> logs;         // ID, CMD
  unordered_map<string, string> users; // ID-> nickname
  vector<string> result;

  string cmd, id, nickname;

  for (string str : record) {
    stringstream ss(str);

    ss >> cmd >> id;
    if (cmd != "Leave") {
      ss >> nickname;
      users[id] = nickname;
    }

    if (cmd != "Change") {
      logs.push_back({id, cmd});
    }
  }

  for (auto logrow : logs) {
    if(logrow[1]=="Enter") result.push_back(users[logrow[0]] + "님이 들어왔습니다.");
    else result.push_back(users[logrow[0]] + "님이 나갔습니다.");
  }

  return result;
}

int main() {
  vector<string> record = {"Enter uid1234 Muzi", "Enter uid4567 Prodo",
                           "Leave uid1234", "Enter uid1234 Prodo",
                           "Change uid4567 Ryan"};
  solution(record);
  return 0;
}
