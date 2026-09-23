#include "basic.h"
#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

//["Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234
// Prodo","Change uid4567 Ryan"]

vector<string> solution(vector<string> record) {
  vector<vector<string>> logs;  // ID, CMD
  vector<vector<string>> users; // ID, nickname
  vector<string> result;

  string cmd, id, nickname;

  for (string str : record) {
    stringstream ss(str);

    ss >> cmd >> id;

    if (cmd != "Leave") {
      ss >> nickname;
    }

    if (cmd != "Change") {
      logs.push_back({id, cmd});
    }

    if (cmd != "Leave") {
      bool found = false;
      for (auto &row : users) {
        if (id == row[0]) {
          row[1] = nickname;
          found = true;
        }
      }
      if (!found) {
        users.push_back({id, nickname});
      }
    }
  }

  for (auto logrow : logs) {
    for (auto userrow : users) {
      if (logrow[0] == userrow[0]) {

        if (logrow[1] == "Enter") {
          result.push_back(userrow[1] + "님이 들어왔습니다.");
        }

        else if (logrow[1] == "Leave") {
          result.push_back(userrow[1] + "님이 나갔습니다.");
        }
      }
    }
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
