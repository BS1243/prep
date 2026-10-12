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

struct Node {
  Node *child[26] = {}; // 알파벳 별 숫자 대응
  bool end = false;
};

void insert(Node *root, string word) {
  Node *cur = root;

  for (char let : word) {
    int idx = let - 'a';

    if (cur->child[idx] == nullptr)
      cur->child[idx] = new Node();

    cur = cur->child[idx];
  }
  cur->end = true;
}

int search(Node *root, string word) {
  Node *cur = root;
  int lastone = 1;
  int nextnode = 0;
  for (int i = 0; i < word.size(); i++) { // 단어 letter별 cycl
    int idx = word[i] - 'a';
    nextnode = 0; // 다음 노드 갯수

    for (int alp = 0; alp < 26; alp++) {
      if (cur->child[alp] != nullptr) { // 자식수 세기
        nextnode++;
      }
    }

    if (cur->end == true ||
        nextnode > 1) { // 2개 이상 분기점 또는 다른 단어의 끝일때 분기점 기록
      lastone = i + 1;
    }
    cur = cur->child[idx];
  }

  int lnextnode = 0;

  for (int alp = 0; alp < 26; alp++) {
    if (cur->child[alp] != nullptr)
      lnextnode++;
  }

  if (lnextnode > 0)
    lastone = word.size();

  return lastone;
}

int solution(vector<string> words) {
  int answer = 0;
  Node *root = new Node();
  for (string s : words) {
    insert(root, s);
  }
  for (string s : words) {
    answer += search(root, s);
    cout << search(root, s) << endl;
  }

  return answer;
}

int main() {
  int n = 6;
  vector<string> edge = {"word", "war", "warrior", "world"};

  cout << solution(edge);
}