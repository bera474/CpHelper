#include <bits/stdc++.h>
using namespace std;

int main() {
  int tt; cin >> tt; string ln;
  vector<vector<int>> qry;
  while (getline(cin, ln)) {
    if (ln.empty()) continue;
    int x; vector<int> q;
    istringstream stream(ln);
    while (stream >> x) q.push_back(x);
    qry.push_back(q);
  }
  return 0;
}