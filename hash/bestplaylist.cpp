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

  for (int i = 0; i < genres.size(); i++) {
    genrecnt[genres[i]] += plays[i];
    table[genres[i]].push_back({plays[i], i});
  }

  // 각 장르 내부 정렬
  for (auto &row : table) {
    sort(row.second.begin(), row.second.end(), [](auto &a, auto &b) {
      if (a.first == b.first) //.first 값이 같으면 b.second가 더 클때 a가 앞으로
        return a.second < b.second;

      return a.first > b.first; // 다르면 a.first>b.first일때 a가 앞으로
    });
  }

  vector<pair<string, int>> genreOrder(genrecnt.begin(), genrecnt.end());

  sort(genreOrder.begin(), genreOrder.end(),
       [](auto &a, auto &b) { return a.second > b.second; });

  for (auto &genre : genreOrder) {
    string name = genre.first;

    answer.push_back(table[name][0].second);

    if (table[name].size() >= 2) {
      answer.push_back(table[name][1].second);
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