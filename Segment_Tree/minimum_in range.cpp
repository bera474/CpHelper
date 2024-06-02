#include <bits/stdc++.h>
using namespace std;

/* problem:-
https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/B*/

struct SegTree
{
  int size;
  vector<int> sums;

  void init(int n)
  {
    size = 1;
    while (size < n)
      size *= 2;
    sums.assign(2 * size, 0ll);
  }
  void build(vector<int> &a, int x, int lx, int rx)
  {
    if (rx - lx == 1)
    {
      if (lx < (int)a.size())
      {
        sums[x] = a[lx];
      }
      return;
    }
    int m = lx + (rx - lx) / 2;
    build(a, 2 * x + 1, lx, m);
    build(a, 2 * x + 2, m, rx);
    sums[x] = min(sums[2 * x + 1], sums[2 * x + 2]);
  }
  void build(vector<int> &a)
  {
    init((int)a.size());
    build(a, 0, 0, size);
  }
  void set(int i, int v, int x, int lx, int rx)
  {
    if (rx - lx == 1)
    {
      sums[x] = v;
      return;
    }
    int m = lx + (rx - lx) / 2;
    if (i < m)
    {
      set(i, v, 2 * x + 1, lx, m);
    }
    else
    {
      set(i, v, 2 * x + 2, m, rx);
    }
    sums[x] = min(sums[2 * x + 1], sums[2 * x + 2]);
  }
  void set(int i, int v) { set(i, v, 0, 0, size); }
  int mini(int l, int r, int x, int lx, int rx)
  {
    if (lx >= r || l >= rx)
      return INT_MAX;
    if (lx >= l && rx <= r)
      return sums[x];
    int m = lx + (rx - lx) / 2;
    int s1 = mini(l, r, 2 * x + 1, lx, m);
    int s2 = mini(l, r, 2 * x + 2, m, rx);
    return min(s1, s2);
  }

  // l is inclusive and r is exclusive
  int mini(int l, int r) { return mini(l, r, 0, 0, size); }
};

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int &x : a)
    cin >> x;
  SegTree st;
  st.build(a);
  while (m--)
  {
    int op;
    cin >> op;
    if (op == 1)
    {
      int i, v;
      cin >> i >> v;
      st.set(i, v);
    }
    else
    {
      int l, r;
      cin >> l >> r;
      cout << st.mini(l, r) << '\n';
    }
  }
  return 0;
}