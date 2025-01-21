class DSU {
  vector<int> f, siz, rnk;

public:
  DSU(int n) {
    siz.assign(n, 1); rnk.assign(n, 0);
    f.resize(n); iota(begin(f), end(f), 0);
  }

  int find(int x) { return (x == f[x] ? x : f[x] = find(f[x])); }
  bool same(int x, int y) { return find(x) == find(y); }

  bool merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    if (rnk[x] < rnk[y]) swap(x, y);
    rnk[x] += (rnk[x] == rnk[y]);
    f[y] = x; siz[x] += siz[y];
    return true;
  }

  int size(int x) { return siz[find(x)]; }
};
