#include <queue>
#include <string>
#include <vector>

#include "../basic.h"

using namespace std;

int bfs(vector<vector<int>>& land, int y, int x, int num) {
	queue<pair<int, int>> q;
	q.push({y, x});
	int size = 0;
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		int cy = cur.first;
		int cx = cur.second;

		if (cy != 0 && land[cy - 1][cx] == 1) {
			q.push({cy - 1, cx});
			land[cy - 1][cx] = num;
			size++;
		}
		if (cy != land.size() - 1 && land[cy + 1][cx] == 1) {
			q.push({cy + 1, cx});
			land[cy + 1][cx] = num;
			size++;
		}
		if (cx != 0 && land[cy][cx - 1] == 1) {
			q.push({cy, cx - 1});
			land[cy][cx - 1] = num;
			size++;
		}
		if (cx != land[0].size() - 1 && land[cy][cx + 1] == 1) {
			q.push({cy, cx + 1});
			land[cy][cx + 1] = num;
			size++;
		}
	}
	return size;
}
int solution(vector<vector<int>> land) {
	int answer = 0;
	int num = 2;
	vector<int> llist;
	for (int i = 0; i < land.size(); i++) {
		for (int j = 0; j < land[0].size(); j++) {
			if (land[i][j] == 1) {
				llist.push_back(bfs(land, i, j, num));
				num++;
			}
		}
	}

	int max = 0;
	for (int i = 0; i < land[0].size(); i++) {
		int total = 0;
		vector<int> visited = {llist.size(), 0};

		for (int j = 0; j < land.size(); j++) {
			if (land[j][i] && visited[land[j][i] - 2]) {
				total += llist[land[j][i] - 2];
				visited[land[j][i] - 2] = true;
			}
		}
		if (total > max) max = total;
	}
	return answer;
}

int main() {
	int n = 6;
	vector<vector<int>> board = {
		{0, 0, 0, 1, 1, 1, 0, 0},
		{0, 0, 0, 0, 1, 1, 0, 0},
		{1, 1, 0, 0, 0, 1, 1, 0},
		{1, 1, 1, 0, 0, 0, 0, 0},
		{1, 1, 1, 0, 0, 0, 1, 1}};

	solution(board);
}