#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


ll expo(ll a, ll b, ll mod) {
  ll res = 1;
  while (b > 0) {
    if (b & 1)
      res = (res * a) % mod;
    a = (a * a) % mod;
    b = b >> 1;
  }
  return res;
}
 
ll mminvprime(ll a, ll b) { 
  return expo(a, b - 2, b); 
}
 
ll mod_add(ll a, ll b, ll m) {
  a = a % m, b = b % m;
  return (((a + b) % m) + m) % m;
}
 
ll mod_mul(ll a, ll b, ll m) {
  a = a % m, b = b % m;
  return (((a * b) % m) + m) % m;
}
 
ll mod_sub(ll a, ll b, ll m) {
  a = a % m, b = b % m;
  return (((a - b) % m) + m) % m;
}
 
struct Hashing {
  string s;
  int n, pr_cnt;
  const ll base = 31;
  vector<vector<ll>> hash, pwr, inv_pwr;
  vector<ll> primes = {1000000009, 100000007};
 
  Hashing(string a) {
    pr_cnt = primes.size();
    hash.resize(pr_cnt);
    pwr.resize(pr_cnt);
    inv_pwr.resize(pr_cnt);
    s = a; n = s.length();
    for (int i = 0; i < primes.size(); i++) {
      pwr[i].resize(n + 1);
      inv_pwr[i].resize(n + 1);
      pwr[i][0] = 1;
      for (int j = 1; j <= n; j++) 
        pwr[i][j] = (base * pwr[i][j - 1]) % primes[i];
      inv_pwr[i][n] = mminvprime(pwr[i][n], primes[i]);
      for (int j = n - 1; j >= 0; j--) 
        inv_pwr[i][j] = mod_mul(inv_pwr[i][j + 1], base, primes[i]);
    }
    for (int i = 0; i < primes.size(); i++) {
      hash[i].resize(n);
      for (int j = 0; j < n; j++) {
        hash[i][j] = ((s[j] - 'a' + 1LL) * pwr[i][j]) % primes[i];
        hash[i][j] = (hash[i][j] + (j > 0 ? hash[i][j - 1] : 0LL)) % primes[i];
      }
    }
  }
 
  vector<ll> subStrHash(int l, int r) {
    vector<ll> res(pr_cnt);
    for (int i = 0; i < pr_cnt; i++) {
      ll val1 = hash[i][r], val2 = l > 0 ? hash[i][l - 1] : 0LL;
      res[i] = mod_mul(mod_sub(val1, val2, primes[i]), inv_pwr[i][l], primes[i]);
    }
    return res;
  }
};