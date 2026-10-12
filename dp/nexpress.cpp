#include "../basic.h"
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int solution(int N, int number) {
    vector<set<int>> dp(9);

    for (int i = 1; i <= 8; i++) {
        int repeated = 0;

        for (int j = 0; j < i; j++) {
            repeated = repeated * 10 + N;
        }

        dp[i].insert(repeated);

        for (int j = 1; j < i; j++) {
            for (int a : dp[j]) {
                for (int b : dp[i - j]) {
                    dp[i].insert(a + b);
                    dp[i].insert(a - b);
                    dp[i].insert(a * b);

                    if (b != 0)
                        dp[i].insert(a / b);
                }
            }
        }

        if (dp[i].count(number))
            return i;
    }

    return -1;
}

int main() {
    cout << solution(5, 12);
}