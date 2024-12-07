#include <bits/stdc++.h>
using namespace std;

/*
Problem:-
https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/C
*/

struct item {
  int m, c;
};
struct SegTree {
  int size;
  vector<item> sums;
  item single(int v) { return {v, 1}; }
  item merge(item a, item b) {
    if (a.m < b.m)
      return a;
    if (a.m > b.m)
      return b;
    return {a.m, a.c + b.c};
  }
  void init(int n) {
    size = 1;
    while (size < n)
      size *= 2;
    sums.resize(2 * size);
  }
  void build(vector<int> &a, int x, int lx, int rx) {
    if (rx - lx == 1) {
      if (lx < (int)a.size()) {
        sums[x] = single(a[lx]);
      }
      return;
    }
    int m = lx + (rx - lx) / 2;
    build(a, 2 * x + 1, lx, m);
    build(a, 2 * x + 2, m, rx);
    sums[x] = merge(sums[2 * x + 1], sums[2 * x + 2]);
  }
  void build(vector<int> &a) {
    init((int)a.size());
    build(a, 0, 0, size);
  }
  void set(int i, int v, int x, int lx, int rx) {
    if (rx - lx == 1) {
      sums[x] = single(v);
      return;
    }
    int m = lx + (rx - lx) / 2;
    if (i < m) {
      set(i, v, 2 * x + 1, lx, m);
    } else {
      set(i, v, 2 * x + 2, m, rx);
    }
    sums[x] = merge(sums[2 * x + 1], sums[2 * x + 2]);
  }
  //  0-based indexing
  void set(int i, int v) { set(i, v, 0, 0, size); }
  item calc(int l, int r, int x, int lx, int rx) {
    if (lx >= r || l >= rx)
      return {INT_MAX, 0};
    if (lx >= l && rx <= r)
      return sums[x];
    int m = lx + (rx - lx) / 2;
    item s1 = calc(l, r, 2 * x + 1, lx, m);
    item s2 = calc(l, r, 2 * x + 2, m, rx);
    return merge(s1, s2);
  }

  //  0-based indexing, l inclusive, r exclusive -> [l...r)
  item calc(int l, int r) { return calc(l, r, 0, 0, size); }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int &x : a)
    cin >> x;
  SegTree st;
  st.build(a);
  while (m--) {
    int op;
    cin >> op;
    if (op == 1) {
      int i, v;
      cin >> i >> v;
      st.set(i, v);
    } else {
      int l, r;
      cin >> l >> r;
      item ans = st.calc(l, r);
      cout << ans.m << ' ' << ans.c << '\n';
    }
  }
  return 0;
}