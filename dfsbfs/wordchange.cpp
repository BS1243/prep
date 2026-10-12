
#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

vector<int> visited;

bool canChange(string a, string b) {
    int diff = 0;

    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i])
            diff++;
    }

    return diff == 1;
}

int bfs(string begin, string target, vector<string> words) {
    queue<pair<string, int>> q;

    q.push({begin, 0});

    while (!q.empty()) {
        string cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (cur == target)
            return cnt;

        for (int i = 0; i < words.size(); i++) {
            if (!visited[i] && canChange(cur, words[i])) {
                visited[i] = 1;
                q.push({words[i], cnt + 1});
            }
        }
    }

    return 0;
}

int solution(string begin, string target, vector<string> words) {
    visited.resize(words.size(), 0);

    return bfs(begin, target, words);
}

