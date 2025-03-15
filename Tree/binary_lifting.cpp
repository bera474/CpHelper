#include <bits/stdc++.h>
using namespace std;
 
const int M = 20;
const int N = 200005;
 
int dep[N];
int par[N][M];
vector<int> adj[N];
 
void dfs(int i, int p, int d) {
  dep[i] = d; par[i][0] = p;
  for (int j = 1; j < M; j++)
    par[i][j] = par[par[i][j - 1]][j - 1];
 
  for (int nei : adj[i]) dfs(nei, i, d + 1);
};
 
void solve() {
  int n, q;
  cin >> n >> q;
 
  for (int i = 2; i <= n; i++) {
    int p; cin >> p; adj[p].push_back(i);
  }
 
  dfs(1, 0, 0);
 
  while (q--) {
    int u, v; cin >> u >> v;
    if (dep[u] < dep[v]) swap(u, v);
 
    int dist = (dep[u] - dep[v]);
    for (int i = 0; i < M; i++)
      if ((dist >> i) & 1) u = par[u][i];
 
    for (int i = M - 1; i >= 0; i--)
      if (par[u][i] != par[v][i])
        u = par[u][i], v = par[v][i];
 
    cout << (u == v ? u : par[u][0]) << '\n';
  }
}
 
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); solve(); return 0;
}