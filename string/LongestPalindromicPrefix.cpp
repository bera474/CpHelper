int LongestPalindromicPrefix(string s) {
  string t = s + '?';
  reverse(s.begin(), s.end());
  t += s; int n = t.length();
  int lps[n];
  fill(lps, lps + n, 0);
  for (int i = 1; i < n; i++) {
    int len = lps[i - 1];
    while (len > 0 && t[len] != t[i])
      len = lps[len - 1];
    if (t[i] == t[len]) len++;
    lps[i] = len;
  }
  return lps[n - 1];
}
