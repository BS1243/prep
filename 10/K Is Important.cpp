

#include <algorithm>
#include <array>
#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;

void solve()
{
  int n, k;
  int total = 0;
  cin >> n >> k;
  int kptr = k - 1;
  int fptr = 0;

  vector<int> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  int ftotal = 0, btotal = 0; // front back total

  for (int i = 0; i < k - 1; i++)
  {
    ftotal += a[i];
    btotal += a[n - i - 1]; // static
  }

  for (int i = 0; i < n - k; i++)
  {

    if (ftotal > btotal)
    { // front가 더 클때 [0] pop , ftotal 갱신
      total += a[fptr];
      ftotal -= a[fptr];

      ftotal += a[fptr + k - 1];
      fptr++;
      kptr++;
    }
    else
    { //[k-1] pop
      total += a[kptr];
      kptr++;
    }
  }
  if (a[kptr] > a[fptr])
  {
    total += a[kptr];
  }
  else
    total += a[fptr];
  cout << total << endl;
  return;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--)
  {
    solve();
  }

  return 0;
}
/**
4
4 2
1 2 3 4
4 4
3 4 1 2
1 1
1
6 3
1 4 8 2 6 3
tcn
n,k
tc>>


1
4 4
3 4 1 2
 **/