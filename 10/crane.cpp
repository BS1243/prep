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
// #:닫힌 space , 0:열린 space

void checkspace(vector<vector<char>>& arr) {
	queue<pair<int, int>> q;

	for (int i = 1; i < arr.size() - 1; i++) {
		for (int j = 1; j < arr[0].size() - 1; j++) {
			if (arr[i][j] == '#') {
				if ((arr[i - 1][j] == '0') || (arr[i + 1][j] == '0') || (arr[i][j - 1] == '0') || (arr[i][j + 1] == '0')) q.push({i, j});
			}  // 열린공간 될것만 q에 push
		}
	}

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		int i = cur.first;
		int j = cur.second;
		arr[i][j] = '0';

		// 열리고 나서 옆의 공간도 열릴수 있는지?
		if (arr[i - 1][j] == '#') q.push({i - 1, j});
		if (arr[i + 1][j] == '#') q.push({i + 1, j});
		if (arr[i][j - 1] == '#') q.push({i, j - 1});
		if (arr[i][j + 1] == '#') q.push({i, j + 1});
	}
	return;
}
void cranepop(char l, vector<vector<char>>& arr) {
	for (int i = 1; i < arr.size() - 1; i++) {
		for (int j = 1; j < arr[0].size() - 1; j++) {
			if (arr[i][j] == l) arr[i][j] = '#';
		}
	}
	return;
}

void normalpop(char l, vector<vector<char>>& arr) {
	for (int i = 1; i < arr.size() - 1; i++) {
		for (int j = 1; j < arr[0].size() - 1; j++) {
			if (arr[i][j] == l) {
				if ((arr[i - 1][j] == '0') || (arr[i + 1][j] == '0') || (arr[i][j - 1] == '0') || (arr[i][j + 1] == '0')) arr[i][j] = '#';
			}
		}
	}
	return;
}

int solution(vector<string> storage, vector<string> requests) {
	vector<vector<char>> arr(storage.size() + 2, vector<char>(storage[0].size() + 2, '0'));

	for (int i = 0; i < storage.size(); i++) {
		for (int j = 0; j < storage[0].size(); j++) arr[i + 1][j + 1] = storage[i][j];
	}

	for (int i = 0; i < requests.size(); i++) {
		if (requests[i].size() > 1) cranepop(requests[i][0], arr);
		else normalpop(requests[i][0], arr);
		checkspace(arr);
	}
	int ans = 0;
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[0].size(); j++) {
			if ((arr[i][j] >= 'A') && (arr[i][j] <= 'Z')) ans++;
		}
	}
	return ans;
}

int main() {
	int n = 6;
	vector<string> storage = {
		"XXXXX",
		"XBXXX",
		"XAXXX",
		"XAXXX",
		"XAAAX"};

	vector<string> requests = {"AA", "B"};
	cout << solution(storage, requests);
}
