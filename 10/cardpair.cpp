
#include <algorithm>
#include <array>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

#include "../basic.h"

using namespace std;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

// 현재 위치에서 목표 카드까지 최소 이동 횟수
int bfs(vector<vector<int>>& board, int sr, int sc, int er, int ec) {
	queue<pair<int, int>> q;
	int dist[4][4];

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			dist[i][j] = -1;

	q.push({sr, sc});
	dist[sr][sc] = 0;

	while (!q.empty()) {
		auto [r, c] = q.front();
		q.pop();

		if (r == er && c == ec)
			return dist[r][c];

		for (int d = 0; d < 4; d++) {
			int nr = r + dr[d];
			int nc = c + dc[d];

			if (nr >= 0 && nr < 4 && nc >= 0 && nc < 4) {
				if (dist[nr][nc] == -1) {
					dist[nr][nc] = dist[r][c] + 1;
					q.push({nr, nc});
				}
			}

			nr = r;
			nc = c;

			while (true) {
				int tr = nr + dr[d];
				int tc = nc + dc[d];

				if (tr < 0 || tr >= 4 || tc < 0 || tc >= 4)
					break;

				nr = tr;
				nc = tc;

				if (board[nr][nc] != 0)
					break;
			}

			if (dist[nr][nc] == -1) {
				dist[nr][nc] = dist[r][c] + 1;
				q.push({nr, nc});
			}
		}
	}

	return -1;
}

int dfs(vector<vector<int>>& board, vector<bool>& visited,
		int maxNum, int r, int c) {
	int answer = INT_MAX;
	bool finished = true;

	for (int i = 1; i <= maxNum; i++) {
		if (visited[i])
			continue;

		vector<pair<int, int>> pos;

		for (int y = 0; y < 4; y++) {
			for (int x = 0; x < 4; x++) {
				if (board[y][x] == i)
					pos.push_back({y, x});
			}
		}

		if (pos.empty())
			continue;

		finished = false;

		auto [r1, c1] = pos[0];
		auto [r2, c2] = pos[1];

		int a = bfs(board, r, c, r1, c1);
		int b = bfs(board, r1, c1, r2, c2);

		int x = bfs(board, r, c, r2, c2);
		int y = bfs(board, r2, c2, r1, c1);

		board[r1][c1] = 0;
		board[r2][c2] = 0;
		visited[i] = true;

		answer = min(answer,
					 a + b + 2 + dfs(board, visited, maxNum, r2, c2));

		answer = min(answer,
					 x + y + 2 + dfs(board, visited, maxNum, r1, c1));

		board[r1][c1] = i;
		board[r2][c2] = i;
		visited[i] = false;
	}

	if (finished)
		return 0;

	return answer;
}

int solution(vector<vector<int>> board, int r, int c) {
	int maxNum = 0;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			maxNum = max(maxNum, board[i][j]);
		}
	}

	vector<bool> visited(maxNum + 1, false);

	return dfs(board, visited, maxNum, r, c);
}

int main() {
	vector<vector<int>> board = {
		{1, 0, 0, 3},
		{2, 0, 0, 0},
		{0, 0, 0, 2},
		{3, 0, 1, 0}};

	cout << solution(board, 1, 0) << '\n';	// 14
}
