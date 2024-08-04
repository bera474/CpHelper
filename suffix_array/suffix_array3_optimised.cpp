// It takes n*log(n) time complexity
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pi pair<int, int>

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  string s; cin >> s; s += '$';
  const int n = s.size();
  vi p(n), c(n);

  // for k = 0;
  vector<pair<char, int>> a(n);
  for (int i = 0; i < n; i++)
    a[i] = {s[i], i};
  sort(begin(a), end(a));

  for (int i = 0; i < n; i++)
    p[i] = a[i].second;

  c[p[0]] = 0;
  for (int i = 1; i < n; i++) 
    c[p[i]] = c[p[i - 1]] + (s[p[i]] != s[p[i - 1]]);

  auto cnt_sort = [&]() {
    vi p_new(n), pos(n), cnt(n);
    for (auto x : c) cnt[x]++;
    pos[0] = 0;
    for (int i = 1; i < n; i++)
      pos[i] = pos[i - 1] + cnt[i - 1];
    for (auto it : p)
      p_new[pos[c[it]]++] = it;
    p = p_new;
  };

  // for other value of k
  for (int k = 0; (1 << k) < n; k++) {
    for (int i = 0; i < n; i++)
      p[i] = (p[i] - (1 << k) + n) % n;

    cnt_sort();
    vi c_new(n); c_new[p[0]] = 0;
    for (int i = 1; i < n; i++) {
      pi prev = {c[p[i - 1]], c[(p[i - 1] + (1 << k)) % n]};
      pi now = {c[p[i]], c[(p[i] + (1 << k)) % n]};
      c_new[p[i]] = c_new[p[i - 1]] + (now != prev);
    }
    c = c_new;
  }

  // vector p stores the sorted index of all the suffix
  for (int i = 0; i < n; i++) 
    cout << p[i] << " \n"[i == n - 1];
  return 0;
}