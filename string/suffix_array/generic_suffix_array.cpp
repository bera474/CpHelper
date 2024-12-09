// It takes n*log(n) time complexity
typedef vector<int> vi;
typedef pair<int, int> pi;

class Suffix_array {
  int n; string s; vi p, c;

  void cnt_sort() {
    vi p_new(n), pos(n), cnt(n);
    for (auto x : c) cnt[x]++;
    pos[0] = 0;
    for (int i = 1; i < n; i++)
      pos[i] = pos[i - 1] + cnt[i - 1];
    for (auto it : p)
      p_new[pos[c[it]]++] = it;
    p = p_new;
  }

public:
  Suffix_array(const string &_s) {
    s = _s; s += '$'; n = s.size();
    p.resize(n); c.resize(n);

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
  }

  // it compares string s ans t
  // return -1 if s small, 0 if s same, 1 if s big
  int comp(const string &t, int idx) {
    for (int j = 0; j < t.size(); j++) {
      if (s[idx + j] == t[j]) continue;
      return (s[idx + j] < t[j] ? -1 : 1);
    }
    return 0;
  }

  int cnt_substr(string &t) {
    int l = -1, r = n, _l = -1;
    while (r > l + 1) {
      int m = (l + r) / 2;
      comp(t, p[m]) < 0 ? l = m : r = m;
    }

    r = n;
    while (r > _l + 1) {
      int m = (_l + r) / 2;
      comp(t, p[m]) > 0 ? r = m : _l = m;
    }
    return r - l - 1;
  }

  bool is_substr(const string &t) {
    int L = 0, H = n - 1;
    while (L <= H) {
      int M = (L + H) / 2;
      int val = comp(t, p[M]);
      if (val == 0) return 1;
      (val == -1 ? L = M + 1 : H = M - 1);
    }
    return 0;
  }

  vector<int> get_arr() { return p; }
};