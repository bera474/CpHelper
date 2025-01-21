class DSU {
  vector<int> f, siz;

public:
  DSU(int n) {
    f.resize(n); siz.assign(n, 1);
    iota(f.begin(), f.end(), 0);
  }

  int find(int x) { return (x == f[x] ? x : f[x] = find(f[x])); }
  bool same(int x, int y) { return find(x) == find(y); }

  bool merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    if (siz[x] < siz[y]) swap(x, y);
    f[y] = x; siz[x] += siz[y];
    return true;
  }

  int size(int x) { return siz[find(x)]; }
};
