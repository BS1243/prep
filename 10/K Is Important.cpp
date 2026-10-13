
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    ll total = 0;

    // 무조건 제거되는 가운데 원소
    for (int i = k - 1; i <= n - k; i++)
        total += a[i];

    // 양쪽에서 선택 가능한 원소
    vector<int> b;

    for (int i = 0; i < n; i++)
    {
        if (i >= k - 1 && i <= n - k)
            continue;

        b.push_back(a[i]);
    }

    int l = 0;
    int r = (int)b.size() - 1;

    int cnt = n - k + 1 - max(0, n - 2 * k + 2);

    while (cnt--)
    {
        total += max(b[l], b[r]);
        l++;
        r--;
    }

    cout << total << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}
