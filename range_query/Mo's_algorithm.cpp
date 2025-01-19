#include <bits/stdc++.h>
using namespace std;

const int BLOCK = 150;

struct Query {
  int l, r, i;
  bool operator<(Query other) const {
    return make_pair(l / BLOCK, r) < 
    make_pair(other.l / BLOCK, other.r);
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  vector<int> v(n);

  int m; cin >> m;
  vector<Query> qry(m);
  for (int i = 0; i < m; i++) {
    int l, r; cin >> l >> r;
    qry[i] = {l - 1, r - 1, i};
  }

  vector<int> ans(m);
  sort(begin(qry), end(qry));

  int cnt = 0;
  auto add = [&](int x) -> void {
    
  };

  auto remove = [&](int x) -> void {
    
  };

  int l = 0, r = -1;
  for (Query q : qry) {
    while (r < q.r) add(v[++r]);
    while (l > q.l) add(v[--l]);
    while (r > q.r) remove(v[r--]);
    while (l < q.l) remove(v[l++]);
    ans[q.i] = cnt;
  }

  for (int i = 0; i < m; i++)
    cout << ans[i] << '\n';
  return 0;
}