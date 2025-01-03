#include <bits/stdc++.h>
using namespace std;
 
vector<int> manacher_odd(string s) {
  int n = s.size(), l = 1, r = 1;
  s = "$" + s + "^"; vector<int> p(n + 2);
  for (int i = 1; i <= n; i++) {
    p[i] = max(0, min(r - i, p[l + (r - i)]));
    while (s[i - p[i]] == s[i + p[i]]) p[i]++;
    if (i + p[i] > r) l = i - p[i], r = i + p[i];
  }
  return vector<int>(begin(p) + 1, end(p) - 1);
}
 
vector<int> manacher(string s) {
  string t = "#";
  for (char c : s) { t += c; t += '#'; }
  return manacher_odd(t);
}
 
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  string s; cin >> s; vector<int> p = manacher(s);
  int mx_len = 0, idx = 0, sz = p.size();
 
  for (int i = 0; i < sz; i++) {
    bool odd = (i & 1);
    int x = (p[i] + odd) / 2, len = 2 * x - odd;
    if (len > mx_len) mx_len = len, idx = (i - !odd) / 2 - x + 1;
  }
  
  cout << s.substr(idx, mx_len) << '\n'; return 0;
}