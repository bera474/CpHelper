int LongestPalindromicPrefix(string s) {
  string t = s + '?';
  reverse(begin(s), end(s));
  t += s; int n = t.length();
  vector<int> lps(n, 0);
  for (int i = 1; i < n; i++) {
    int len = lps[i - 1];
    while (len > 0 && t[len] != t[i])
      len = lps[len - 1];
    if (t[i] == t[len]) len++;
    lps[i] = len;
  }
  return lps[n - 1];
}
