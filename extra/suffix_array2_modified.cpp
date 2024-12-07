// It takes n*log(n) time complexity
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  string s; cin >> s; s += '$';
  const int n = s.size();
  vector<int> p(n), c(n);

  // for k = 0;
  vector<pair<char, int>> v(n);
  for (int i = 0; i < n; i++)
    v[i] = {s[i], i};
  sort(v.begin(), v.end());

  for (int i = 0; i < n; i++)
    p[i] = v[i].second;
  c[p[0]] = 0;
  for (int i = 1; i < n; i++)
    c[p[i]] = c[p[i - 1]] + (s[p[i]] != s[p[i - 1]]);

  vector<pair<pair<int, int>, int>> a(n);

  auto radix_sort = [&]() {
    vector<int> cnt, pos(n);
    vector<pair<pair<int, int>, int>> a_new(n);
    for (int i = 0; i < 2; i++) {
      cnt.assign(n, 0);
      for (auto it : a)
        cnt[(i ? it.first.first : it.first.second)]++;
      pos[0] = 0;
      for (int i = 1; i < n; i++)
        pos[i] = pos[i - 1] + cnt[i - 1];
      for (auto it : a)
        a_new[pos[(i ? it.first.first : it.first.second)]++] = it;
      a = a_new;
    }
  };

  // for other value of k
  for (int k = 0; (1 << k) < n; k++) {
    for (int i = 0; i < n; i++)
      a[i] = {{c[i], c[(i + (1 << k)) % n]}, i};
    radix_sort();
    for (int i = 0; i < n; i++)
      p[i] = a[i].second;
    c[p[0]] = 0;
    for (int i = 1; i < n; i++)
      c[p[i]] = c[p[i - 1]] + (a[i].first != a[i - 1].first);
  }

  // vector p stores the sorted index of all the suffix
  for (int i = 0; i < n; i++)
    cout << p[i] << " \n"[i == n - 1];
  return 0;
}