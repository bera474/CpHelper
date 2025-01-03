template <typename T> class DisjointSparseTable {
  int n;
  vector<vector<T>> mat;
  inline T merge(T a, T b) const { return (a + b); }

public:
  DisjointSparseTable(const vector<T> &a) : n(int(a.size())) {
    mat.push_back(a);
    for (int p = 1; (1 << p) < n; p++) {
      mat.emplace_back(n);
      for (int mid = 1 << p; mid < n; mid += 1 << (p + 1)) {
        mat[p][mid - 1] = a[mid - 1];
        for (int j = mid - 2; j >= mid - (1 << p); j--)
          mat[p][j] = merge(a[j], mat[p][j + 1]);
        mat[p][mid] = a[mid];
        for (int j = mid + 1; j < min(n, mid + (1 << p)); j++)
          mat[p][j] = merge(mat[p][j - 1], a[j]);
      }
    }
  }

  // r exclusive [l...r)
  T Query(int l, int r) const {
    assert(0 <= l && l < r && r <= n);
    if (r - l == 1) return mat[0][l];
    int p = 31 - __builtin_clz(l ^ (r - 1));
    // int p = bit_width(unsigned(l ^ (r - 1))) - 1;
    return merge(mat[p][l], mat[p][r - 1]);
  }
};