#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vb vector<bool>

const int MX = 1e5 + 5;
int hgt[MX], child[MX], min_pos[MX], pnt[MX];

// https://codeforces.com/contest/1986/problem/F

int dfs(int s, int h, int p, vi adj[], vb &vis) {
  vis[s] = 1, hgt[s] = h; int chld = 1; pnt[s] = p;
  for (int &it : adj[s]) if(!vis[it]) chld += dfs(it, h + 1, s, adj, vis);
  return child[s] = chld;
}


int find_min_pos(int node, int pnt, vi adj[], vb &vis) {
  vis[node] = 1; int mn = hgt[node];
  for (auto nei : adj[node]) {
    if (!vis[nei]) mn = min(mn, find_min_pos(nei, node, adj, vis));
    else if (nei != pnt) mn = min(mn, hgt[nei]);
  } return min_pos[node] = mn;
}


void solve() {
  int n, m;
  cin >> n >> m;

  vi adj[n];
  for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v; --u, --v;
    adj[u].push_back(v); adj[v].push_back(u);
  }

  vb vis1(n, 0), vis2(n, 0);
  dfs(0, 0, -1, adj, vis1);
  find_min_pos(0, -1, adj, vis2);

  auto nc2 = [](ll n) -> ll { return n * (n - 1) / 2; };
  auto calc = [&](int x) -> ll { return nc2(x) + nc2(n - x); };

  ll ans = nc2(n);
  
  // to avoid the hypothetical bridge
  // edge btw 0 and -1 i is started from 1.
  for (int i = 1; i < n; i++)
    if (min_pos[i] >= hgt[i]) {
      // edge btw i and pnt[i] is bridge
      ans = min(ans, calc(child[i]));
    }

  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tt; cin >> tt; while (tt--) solve(); return 0;
}