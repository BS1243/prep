#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
  vector<int> answer;

  unordered_map<string, int> genrecnt; // 장르->총횟수
  unordered_map<string, vector<pair<int, int>>> table;
  // 장르 -> <재생수, 고유번호>
  //table[string(장르)][vector<pair>의 번호].first/second

  for (int i = 0; i < genres.size(); i++) {
    genrecnt[genres[i]] += plays[i];
    table[genres[i]].push_back({plays[i], i});
  }

  // table 정렬 각 장르별-(재생수,고유번호)순
  for (auto &row : table) { //uo [string]<plays,uid>
    sort(row.second.begin(), row.second.end(), [](auto &a, auto &b) {
      if (a.first == b.first) //.first 값이 같으면 b.second가 더 클때 a가 앞으로
        return a.second < b.second;

      return a.first > b.first; // 다르면 a.first>b.first일때 a가 앞으로
    });
  }

  vector<pair<string, int>> genrecntv(genrecnt.begin(), genrecnt.end());//genrecnt uo->vector

  sort(genrecntv.begin(), genrecntv.end(),
       [](auto &a, auto &b) { return a.second > b.second; }); // play순 정렬

  for (auto &ptr : genrecntv) { 
    string name = ptr.first;
    answer.push_back(table[name][0].second);//table[장르별][pair벡터의 1번째꺼]의 uid.
    if (table[name].size() >= 2) {//장르에 노래 2개이상 있으면
      answer.push_back(table[name][1].second);//table[장르별][pair벡터의 2번째꺼]의 uid.
    }
  }

  return answer;
}

int main() {
  vector<string> genres = {"classic", "pop", "classic", "classic", "pop"};

  vector<int> plays = {500, 600, 150, 800, 2500};

  vector<int> result = solution(genres, plays);

  for (int x : result) {
    cout << x << " ";
  }
}