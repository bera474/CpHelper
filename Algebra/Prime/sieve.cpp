#include <bits/stdc++.h>
using namespace std;

// Source : https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html

const int N = 1e5;
vector<bool> is_prime(N + 1, true);

void sieve() {
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i * i <= N; i++) {
    if (is_prime[i]) {
      for (int j = i * i; j <= N; j += i)
        is_prime[j] = false;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  sieve();
  return 0;
}