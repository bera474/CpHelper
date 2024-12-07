// To make the suffix array takes n*log(n) time complexity
// To search the given string is a substr or not it take log(n)*len(temp str) .
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
    pos[0] = 0;
    for (auto x : c) cnt[x]++;
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

    cnt_sort(); vi c_new(n); c_new[p[0]] = 0;
    for (int i = 1; i < n; i++) {
      pi prev = {c[p[i - 1]], c[(p[i - 1] + (1 << k)) % n]};
      pi now = {c[p[i]], c[(p[i] + (1 << k)) % n]};
      c_new[p[i]] = c_new[p[i - 1]] + (now != prev);
    }
    c = c_new;
  }

  int q; cin >> q; while (q--) {
    string t; cin >> t;
    // This func will check whether t is a substr of s or not
    auto is_substr = [&](string &t) -> bool {
      // compare func return -1 if s small, 0 if s same, 1 if s big
      auto compare = [&](int idx) -> int {
        for (int j = 0; j < t.size(); j++) {
          if (s[idx + j] == t[j]) continue;
          return (s[idx + j] < t[j] ? -1 : 1);
        } return 0;
      };

      int L = 0, H = n - 1;
      while (L <= H) {
        int M = (L + H) / 2;
        int val = compare(p[M]);
        if (val == 0) return 1;
        (val == -1 ? L = M + 1 : H = M - 1);
      } return 0;
    };
    cout << (is_substr(t) ? "Yes" : "No") << endl;
  } return 0;
}