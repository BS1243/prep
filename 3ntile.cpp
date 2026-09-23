#include <string>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

int solve(int n)
{
    if (n % 2 != 0)
        return 0;
    const long long MOD = 1000000007;

    int k = 2;
    long long special = 0;
    vector<long long> dp(n + 3, 0);
    dp[0] = 1;

    for (int k = 2; k <= n; k += 2)
    {
        dp[k] = (dp[k - 2] * 3 + special) % MOD;
        special = (2 * dp[k - 2] + special) % MOD;//그 다음 수의 special 계산!
    }

    return dp[n];
}

int solution(int n)
{
    return solve(n);
}

int main()
{
    cout << solution(6);
}