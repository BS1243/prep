#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

#include "../basic.h"

using namespace std;

long long cton(string s) {
	long long num = 0;

	for (int i = 0; i < s.size(); i++) {
		int t = s[s.size() - i - 1] - 'a' + 1;
		num += pow(26, i) * t;
	}
	return num;
}

string ntoc(long long num) {
	string s = "";
	while (num > 0) {
		num--;
		s += char(num % 26 + 'a');
		num /= 26;
	}
	reverse(s.begin(), s.end());
	return s;
}

string solution(long long n, vector<string> bans) {
	vector<long long> bannum;
	for (string s : bans) bannum.push_back(cton(s));
	sort(bannum.begin(), bannum.end());
	pr1(bannum);
	int frontn = 0;
	for (long long x : bannum) {
		if (x <= n + frontn) frontn++;
	}

	n += frontn;
	return ntoc(n);
}

int main() {
	long long n = 7388;
	vector<string> storage = {
		"gqk", "kdn", "jxj", "jxi", "fug", "jxg", "ewq", "len", "bhc"};

	cout << solution(n, storage);
}
