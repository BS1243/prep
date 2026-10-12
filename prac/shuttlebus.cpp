#include "../basic.h"
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

string itot(int min) {
  min += 540;
  int hour = min / 60;
  int minute = min % 60;

  string h = to_string(hour);
  string m = to_string(minute);

  if (hour < 10)
    h = "0" + h;
  if (minute < 10)
    m = "0" + m;

  return h + ":" + m;
}

string solution(int n, int t, int m, vector<string> timetable) {
  vector<int> humantbl, bustbl; // Timetable

  int cal, pr;
  for (int i = 0; i < n; i++) {
    bustbl.push_back(i * t);
  }

  for (string str : timetable) {
    cal = -540;
    cal += stoi(str.substr(0, 2)) * 60;
    cal += stoi(str.substr(3, 2));
    if (cal > bustbl.back()) {
      continue; // 막차 뒤에 오는사람
    }
    humantbl.push_back(cal);
  }
  sort(humantbl.begin(), humantbl.end());

  int bus = 0, hm = 0;

  while (bus < bustbl.size()) {
    int cnt = 0;
    
    while (hm < humantbl.size() && humantbl[hm] <= bustbl[bus] && cnt < m) {
      hm++;
      cnt++;
    }

    if (bus == bustbl.size() - 1) {
      if (cnt < m) {
        return itot(bustbl[bus]);
      }
      return itot(humantbl[hm - 1] - 1);
    }

    bus++;
  }
  return "a";
}

int main() {
  vector<string> record = {"09:00", "09:00", "09:00", "09:00"};
  cout << solution(2, 1, 2, record);
  return 0;
}
