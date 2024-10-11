#include <bits/stdc++.h>
using namespace std;

// Source : https://cp-algorithms.com/algebra/prime-sieve-linear.html#algorithm

const int N = 10'000'000;
vector<int> spf(N + 1);
vector<int> pr;

void linear_sieve() {
  for (int i = 2; i <= N; ++i) {
    if (spf[i] == 0) {
      spf[i] = i;
      pr.push_back(i);
    }
    for (int j = 0; i * pr[j] <= N; ++j) {
      spf[i * pr[j]] = pr[j];
      if (pr[j] == spf[i]) break;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  linear_sieve();
  return 0;
}